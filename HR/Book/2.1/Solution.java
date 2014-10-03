public class Solution {
    static class Node {
        int data;
        Node next;
        Node(int _data) {
            data = _data;
            next = null;
        }
    }
    //2.5
    public static Node findBeginning(Node list) {
        Node x1 = list, x2 = list;
        int y = 0;
        do {
            y ++;
            System.out.println("x1:" + x1.data);
            System.out.println("x2:" + x2.data);
            x1 = x1.next;
            x2 = x2.next.next;

        } while (x1 != x2);
        System.out.println("y = " + y);
        x1 = list;
        x2 = list;
        for (int i = 0 ; i < y ; i ++)
            x2 = x2.next;
        while (x1 != x2) {
            x2 = x2.next;
            x1 = x1.next;
        }
        return x1;
    }
    public static void main(String args[]) {
        int n = 10; int cycle = 0;
        Node [] arr = new Node [n];
        for (int i = 0 ; i < n ; i ++) {
            arr[i] = new Node(i + 1);
        }
        for (int i = 0 ; i < n-1 ; i ++)
            arr[i].next = arr[i+1];
        arr[n-1].next = arr[cycle];
        Node X = findBeginning(arr[0]);
        System.out.println(X.data);
    }
}