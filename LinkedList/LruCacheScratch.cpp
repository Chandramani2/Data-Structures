#include<bits/stdc++.h>
// ... (Node and LRUCache class definitions as provided previously)
template <typename Key, typename Value>
class Node {
public:
    Key key;
    Value value;
    Node* prev;
    Node* next;
    Node(Key k, Value v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

template <typename Key, typename Value>
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity), size_(0), head_(nullptr), tail_(nullptr) {}

    Value get(const Key& key) {
        if (key_to_node_.find(key) == key_to_node_.end()) {
            return Value(); // Handle key not found
        }
        Node<Key, Value>* node = key_to_node_[key];
        moveToHead(node);
        return node->value;
    }

    void put(const Key& key, const Value& value) {
        if (key_to_node_.find(key) != key_to_node_.end()) {
            Node<Key, Value>* node = key_to_node_[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node<Key, Value>* newNode = new Node<Key, Value>(key, value);
            addNode(newNode);
            key_to_node_[key] = newNode;
            size_++;
            if (size_ > capacity_) {
                removeTail();
            }
        }
    }

private:
    int capacity_;
    int size_;
    Node<Key, Value>* head_;
    Node<Key, Value>* tail_;
    std::unordered_map<Key, Node<Key, Value>*> key_to_node_; // Using std::unordered_map for hash table

    void addNode(Node<Key, Value>* node) {
        node->next = head_;
        if (head_ != nullptr) {
            head_->prev = node;
        }
        head_ = node;
        if (tail_ == nullptr) {
            tail_ = head_;
        }
    }

    void removeNode(Node<Key, Value>* node) {
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            head_ = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            tail_ = node->prev;
        }
    }

    void moveToHead(Node<Key, Value>* node) {
        removeNode(node);
        addNode(node);
    }

    void removeTail() {
        key_to_node_.erase(tail_->key);
        removeNode(tail_);
        size_--;
    }
};

int main() {
    LRUCache<int, std::string> cache(3); // Cache with capacity 3

    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");

    std::cout << cache.get(2) << std::endl;  // Output: "two"

    cache.put(4, "four"); // Evicts the least recently used key (1)

    std::cout << cache.get(1) << std::endl;  // Output: (default value for Value)

    return 0;
}
