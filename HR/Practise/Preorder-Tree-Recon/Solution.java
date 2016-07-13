import java.io.*;
import java.util.*;

/* Given a preorder walk of the binary search tree, reconstruct the tree. */

public class Solution {
    
    
    public Node solve(final int [] a) throws IOException {
        Stack<Node> stack = new Stack<Node>();
        Node rightmost = new Node(a[0]);
        for (int i = 1; i < n; i ++) {
            Node cur = new Node(a[i]);
            if (stack.isEmpty()) {
                stack.push(cur);
            } else {
                if (stack.peek().val > a[i]) {
                    stack.peek().left = cur;
                    stack.push(cur);
                } else {
                    while (!stack.isEmpty() && stack.peek().val < a[i]) {
                        stack.poll();
                    }
                    if (stack.isEmpty()) {
                        rightmost.right = cur;
                        rightmost = cur;
                        stack.push(rightmost);
                    } else {
                        stack.peek().left.right = cur;
                        stack.push(cur);
                        
                    }
                }
            }
        }
    }

    private Node solveHelper() {
        
    }
    
    
    public Solution() throws IOException {
        
    }
    
    public static void main(String args[]) throws IOException {
        Node treeNode = new Solution().solve();
    }
    
    public class Node {
        Node left, right;
        final int val;
        public Node(int val) {
            this.val = val;
        }
    }
}