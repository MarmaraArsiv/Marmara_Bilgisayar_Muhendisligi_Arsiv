public class Node {
    int id;
    Node next;
    Node prev;

    public Node(int id, Node next) {
        this.id = id;
        this.next = null;
        this.prev=null;
    }

    public Node(int id) {
        this.id = id;
        this.next = null;
        this.prev=null;
    }
}
