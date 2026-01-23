public class Node {
    String key;
    int value;
    Node next;
    Node prev;
    public Node(String key, int value) {
        this.key = key;
        this.value = value;
        next = prev = null;
    }
}
