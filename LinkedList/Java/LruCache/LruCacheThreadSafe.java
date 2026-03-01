import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.locks.ReentrantLock;

/**
 * A thread-safe, generic LRU Cache.
 * @param <K> The type of keys maintained by this cache
 * @param <V> The type of mapped values
 */
public class LruCacheThreadSafe<K, V> {

    // Internal Doubly Linked List Node
    private class Node {
        K key;
        V value;
        Node prev, next;

        Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    private Node head, tail;
    private int size;
    private final int capacity;
    private final Map<K, Node> map = new HashMap<>();
    private final ReentrantLock lock = new ReentrantLock();

    public LruCacheThreadSafe(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Capacity must be greater than 0");
        }
        this.capacity = capacity;
        this.size = 0;
    }

    /**
     * Retrieves an entry from the cache.
     * Returns null if the key is not found or if the key provided is null.
     */
    public V get(K key) {
        if (key == null) return null;

        lock.lock();
        try {
            Node node = map.get(key);
            if (node == null) return null;

            moveToHead(node);
            return node.value;
        } finally {
            lock.unlock();
        }
    }

    /**
     * Adds or updates an entry. 
     * Throws NullPointerException if key or value is null.
     */
    public void put(K key, V value) {
        if (key == null || value == null) {
            throw new NullPointerException("LRU Cache does not support null keys or values");
        }

        lock.lock();
        try {
            if (map.containsKey(key)) {
                Node node = map.get(key);
                node.value = value;
                moveToHead(node);
            } else {
                Node newNode = new Node(key, value);

                // Eviction if at capacity
                if (size >= capacity) {
                    evictOldest();
                }

                addNode(newNode);
                map.put(key, newNode);
                size++;
            }
        } finally {
            lock.unlock();
        }
    }

    private void evictOldest() {
        if (tail != null) {
            map.remove(tail.key);
            removeNode(tail);
            size--;
        }
    }

    // --- Atomic pointer operations (Internal use only) ---

    private void addNode(Node node) {
        node.next = head;
        node.prev = null;
        if (head != null) head.prev = node;
        head = node;
        if (tail == null) tail = head;
    }

    private void removeNode(Node node) {
        if (node.prev != null) node.prev.next = node.next;
        else head = node.next;

        if (node.next != null) node.next.prev = node.prev;
        else tail = node.prev;
    }

    private void moveToHead(Node node) {
        removeNode(node);
        addNode(node);
    }

    public int getSize() {
        lock.lock();
        try { return size; }
        finally { lock.unlock(); }
    }
}