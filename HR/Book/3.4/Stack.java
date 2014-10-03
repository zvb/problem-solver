public class Stack {
    private class Node {
        int data;
        Node next;
        public Node(int _data) {
            data = _data;
        }
    }

    Node top;
    public Stack() {
        
    }
    public void push(int x) {
        if (top == null)
            top = new Node(x);
        else {
            Node newTop = new Node(x);
            newTop.next = top;
            top = newTop;
        }
    }
    public int poll() {
        if (top != null) {
            int res = top.data;
            top = top.next;
            return res;
        }
    }
    public int peek() {
        if (top != null) {
            int res = top.data;
            return res;
        }
    }
}