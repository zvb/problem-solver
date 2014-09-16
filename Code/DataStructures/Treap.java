import java.util.*;
import java.io.*;
public class Treap {
    public static class Node {
        int x, y;
        Node left, right;
        public Node(int _x, int _y) {
            x = _x;
            y = _y;
        }
    }
    public Treap() {}
    public Treap(Node _root) {
        root = _root;
    }
    Node root;
    void split(int x, Treap l, Treap r) {
        System.out.println("Splitting " + toString() + " on " + x);
        if (this.root == null) {
            System.out.println("root is null");
            l = new Treap();
            r = new Treap();
        } else if (x < root.x) {
            Treap leftTreap = new Treap(root.left);
            //Treap sLeft = new Treap(), sRight = new Treap();
            Treap sLeft = null, sRight = null;
            leftTreap.split(x, sLeft, sRight);
            this.root.left = sRight.root;
            l = sLeft;
            r = this;
        } else {
            Treap rightTreap = new Treap(root.right);
            Treap sLeft = null, sRight = null;
            
            rightTreap.split(x, sLeft, sRight);
            System.out.println("Splitted");
            System.out.println("sLeft, sRight:" + sLeft.toString() + "|" + sRight.toString());
            System.out.println("root=" + root.x + ", " + root.y);
            this.root.right = sLeft.root;
            
            r = sRight;
            l = this;
        
        }
    }
    void insert(Node node) {
        if (root == null) root = node;
        else if (root.y < node.y) {
            Treap sLeft = new Treap(), sRight = new Treap();
            split(node.x, sLeft, sRight);
            System.out.println("[insert] after split:" + sLeft + " | " + sRight);
            node.left = sLeft.root;
            node.right = sRight.root;
            this.root = node;
        } else {
            if (node.x < root.x) {
                Treap leftTreap = new Treap(root.left);
                leftTreap.insert(node);
                root.left = leftTreap.root;
            } else {
                Treap rightTreap = new Treap(root.right);
                rightTreap.insert(node);
                root.right = rightTreap.root;
            }
        }
    }
    public String toString() {
        if (root == null) return "";
        Treap leftTreap = new Treap(root.left);
        Treap rightTreap = new Treap(root.right);
        return leftTreap.toString() + String.format("( %d, %d ) ", root.x, root.y) + rightTreap.toString();
    }
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(System.in);
        Treap treap = new Treap();
        int n = in.nextInt();
        for (int i = 1 ; i <= n ; i++) {
            treap.insert(new Node(in.nextInt(), in.nextInt()));
            System.out.println(treap.toString());
        }
        System.out.println();
        in.close();
    }
}

