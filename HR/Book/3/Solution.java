import java.util.Scanner;
public class Solution {
    static class Stack {
        class Node {
            int data;
            Node next;
            Node nextMin;
            public Node(int x) {
                next = nextMin = null;
                data = x;
            }
        }
        Node last;
        Node min;
        public Stack() {
            
        }
        public void push(int data) {
            if (last == null) {
                last = new Node(data);
                min = last;
            } else {
                Node added = new Node(data);
                added.next = last;
                last = added;
                if (data < min.data) {
                    last.nextMin = min;
                    min = last;
                }
            }
        }
        public int poll() {
            if (last == null) return -1;
            int ret = last.data;
            if (last == min) {
                min = last.nextMin;
            }
            last = last.next;
            return ret;
        }
        public int peek() {
            if (last == null) return -1;
            return last.data;
        }
        public int getMin() {
            if (min == null) return -1;
            return min.data;
        }
        public String toString() {
            Node runner = last;
            String result = "top ->[ ";
            while (runner != null) {
                result += runner.data + " ";
                runner = runner.next;
            }
            result += "]";
            return result;
        }
    }
    public static void main(String args[]) {
        Stack stack = new Stack();
        int x = -1;
        Scanner in = new Scanner(System.in);
        while ( (x = in.nextInt()) != -1 ) {
            if (x == 1) stack.push(in.nextInt());
            else if (x == 2) System.out.println(stack.poll());
            else System.out.println(stack.getMin());
            System.out.println(stack);
            
        }
        in.close();
    }
}