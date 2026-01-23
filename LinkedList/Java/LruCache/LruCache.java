import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class LruCache {
    private Node head;
    private Node tail;
    private int size;
    private int capacity;
    private HashMap<String, Node> map = new HashMap<>();
    public LruCache(int capacity) {
        this.capacity = capacity;
        head = tail=null;
        this.size = 0;
    }

    public int get(String key) {
        if(map.containsKey(key)) {
            Node node = map.get(key);
            moveToHead(node);
            return node.value;
        }
        return -1;
    }

    public void put(String key, int value) {
       if(map.containsKey(key)){
           Node node = map.get(key);
           node.value = value;
           moveToHead(node);
       }
       else{
           Node newNode = new Node(key, value);
           addNode(newNode);
           map.put(key, newNode);
           size++;
           if(size>capacity){
               removeTail();
           }
       }
    }

    private void addNode(Node node) {
        node.next = head;
        if(head!=null) {
            head.prev = node;
        }
        head = node;
        if(tail==null) {
            tail = head;
        }
    }

    private void removeNode(Node node) {
        if(node.prev!=null) {
            node.prev.next = node.next;
        }
        else{
            head = node.next;
        }
        if(node.next!=null) {
            node.next.prev = node.prev;
        }
        else{
            tail = node.prev;
        }
    }

    private void moveToHead(Node node) {
        removeNode(node);
        addNode(node);
    }

    private void removeTail() {
        map.remove(tail.key);
        removeNode(tail);
        size--;
    }

    public void printAll() {
        for(Map.Entry<String, Node> x: map.entrySet()){
            System.out.println(x.getKey() + ": " + x.getValue().value);
        }
        System.out.println("=====================================");
    }

}
