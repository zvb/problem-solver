import java.io.*;
import java.util.*;

public class SegmentTree {
    public final int N;
    private long [] t;
    private long [] add;
    public SegmentTree(int [] arr) {
        N = arr.length;
        t = new long [4 * N];
        add = new long [4 * N];
        build(arr, 1, 0, N - 1);
    }
    private void build(int [] a, int v, int L, int R) {
        if (L == R)
            t[v] = a[L];
        else {
            int mid = (L + R) / 2;
            build(a, 2*v, L, mid);
            build(a, 2*v + 1, mid + 1, R);
            t[v] = Math.min(t[2*v], t[2*v+1]);
        }
    }
    public void add(int l, int r, int val) {
        _add(1, 0, N - 1, l, r, val);
    }
    public long getMin(int l, int r) {
        return _getMin(1, 0, N - 1, l, r);
    }
    private long _getMin(int v, int L, int R, int l, int r) {
        push(v, L, R);
        if (l > r) return Long.MAX_VALUE;
        if (L == l && R == r)
            return t[v];
        int mid = (L + R) / 2;
        return Math.min(_getMin(2*v, L, mid, l, Math.min(mid, r)),
                        _getMin(2*v+1, mid + 1, R, Math.max(l, mid + 1), r));
    }
    private void push(int v, int L, int R) {
        if (L == R) {
            t[v] += add[v];
            add[v] = 0;
        } else {
            add[2*v] += add[v];
            add[2*v+1] += add[v];
            t[v] += add[v];
            add[v] = 0;
        }
    }
    private void _add(int v, int L, int R, int l, int r, int val) {
        //System.out.println("v = " + v + " L = " + L + " R = " + R + " l = " + l + " r = " + r);
        if (l > r) return;
        push(v, L, R);
        int mid = (L + R) / 2;
        
        if (L == l && r == R) {
            add[v] += val;
            push(v, L, R);
        } else {
            _add(2*v, L, mid, l, Math.min(mid, r), val);
            _add(2*v+1, mid + 1, R, Math.max(mid + 1, l), r, val);
            push(v, L, R);
            push(2*v, L, mid);
            push(2*v+1, mid + 1, R);
            t[v] = Math.min(t[2*v], t[2*v+1]);
        }
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        for (int i = 0 ; i + 1 < N ; i ++)
            sb.append(getMin(i, i) + ", ");
        if (N > 0)
            sb.append(getMin(N - 1, N - 1));
        sb.append(']');
        return sb.toString();
    }
    public static void main(String args[]) throws FileNotFoundException {
        final int n = 10;
        int [] a = new int [n];
        SegmentTree tree = new SegmentTree(a);
        //Scanner sc = new Scanner (new FileReader("in.txt"));
        Scanner sc = new Scanner (System.in);
        int q = sc.nextInt();
        while (q -- > 0) {
            int t = sc.nextInt();
            if ( t == 1 ) {
                int l = sc.nextInt(), r = sc.nextInt();
                System.out.println(tree.getMin(l, r));
            } else {
                int l = sc.nextInt(), r = sc.nextInt(), val = sc.nextInt();
                tree.add(l, r, val);
            }
        }
        
        
        
    }
}








