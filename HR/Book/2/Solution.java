import java.io.*;
import java.util.*;

public class Solution {
    class Node {
        Node next;
        int data;
        public Node(int data) {
            next = null;
            this.data = data;
        }
        public String toString() {
            String res = "[ ";
            Node runner = this;
            while (runner != null) {
                res += runner.data + " ";
                runner = runner.next;
            }
            res += "]";
            return res;
        }
    }
    public class LinkedList {
        Node head, tail;
        public LinkedList() {
            head = null;
            tail = null;
        }
        public void add(int data) { // adds to the back of ll
            if (tail == null) {
                tail = new Node(data);
                head = tail;
            } else {
                tail.next = new Node(data);
                tail = tail.next;
            }
        }
        public void erase(int data) { // removes first occurence of data in LL
            if (head == null) return;
            if (head.data == data) {
                head = head.next;
                return;
            }
            Node cur = head;
            while (cur.next != null && cur.next.data != data)
                cur = cur.next;
            if (cur.next != null) {
                cur.next = cur.next.next;
            }
        }
        public String toString() {
            String result = "[";
            Node cur = head;
            while (cur != null) {
                result += cur.data + " ";
                cur = cur.next;
            }
            result += "]";
            return result;
        }
        public void removeDuplicates() {        // 2.1
            if (head == null) return;
            Node it1 = head.next;
            Node last = head;
            while (it1 != null) {
                boolean wasEarlier = false;
                for (Node it2 = head ; it2 != last.next ; it2 = it2.next) {
                    if (it2.data == it1.data) { // it1 should be removed
                        wasEarlier = true;
                        break;
                    }
                }
                if (!wasEarlier) {
                    last.next = it1;
                    last = it1;
                }
                it1 = it1.next;
            }
            tail = last;
            last.next = null;
        }
        public Node get(int index) {
            Node runner = head;
            for (int i = 0  ; i < index && runner != null ; i ++, runner = runner.next)
            {
                ;
            }
            return runner;
        }
        /// 2.2
        int length() {
            int len = 0;
            for (Node runner = head; runner != null ; runner = runner.next)
                len ++;
            return len;
        }
        public Node getNthToLast(int n) { // n [1, len];
            int len = length();
            return get(len - n);
        }
    }
    //2.3 a->b->c->d->e
    //          ^
    // Assumption: c is not last element in list
    public static Node removeByReference(Node c) {
        Node cc = c;
        while (cc.next != null) {
            cc.data = cc.next.data;
            if (cc.next.next == null)
                cc.next = null;
            else
                cc = cc.next;
        }
        return c;
    }
    // 2.4
    public Node addNumbers(Node a, Node b) {
        Node result = null;
        int carry = 0;
        Node previous = null;
        for ( ; a != null || b != null || carry > 0 ; ) {
            //System.out.println(a + " " + b + " " + carry);
            int x = 0;
            if (a != null) {
                x += a.data;
                a = a.next;
            }
            if (b != null) {
                x += b.data;
                b = b.next;
            }
            x += carry;
            if (previous == null) {
                previous = new Node(x%10);
                result = previous;
            }
            else {
                previous.next = new Node(x%10);
                previous = previous.next;
            }
            carry = x / 10;
        }
        return result;
    }
    public Solution() {
        Scanner in = new Scanner(System.in);
        LinkedList a = new LinkedList(), b = new LinkedList();
        int x;
        while ( (x = in.nextInt()) != -1 ) {
            a.add(x);
        }
        System.out.println(a);
        while ( (x = in.nextInt()) != -1 ) {
            b.add(x);
        }
        System.out.println(b);
        Node aHead = a.head, bHead = b.head;
        Node aPlusB = addNumbers(aHead, bHead);
        System.out.println(aPlusB.toString());
        in.close();
    }
    public static void main(String args[]) throws IOException {
        new Solution();
    }
}