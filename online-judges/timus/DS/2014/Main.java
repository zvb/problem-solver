import java.io.*;
import java.util.*;

public class Main {
    final static int [] m = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n;
    SegmentTree tree;
    public void solve() throws IOException {
        long sum = 0;
        n = nextInt();
        final int z = 365 * 24 * 60;
        int [] a = new int [z];
        tree = new SegmentTree(a);
        for (int i = 0 ; i < n ; i ++) {
            int val = nextInt();
            int time = getTime(next(), next());
            tree.add(time, z - 1, val);
            out.println(Math.min(tree.getMin(0, z - 1), 0));
        }
    }
    
    int getTime(String f, String s) {

        int month = Integer.parseInt(f.substring(3, 5));
        int day = Integer.parseInt(f.substring(0, 2)) - 1;
        int hour = Integer.parseInt(s.substring(0, 2));
        int minute = Integer.parseInt(s.substring(3, 5));
        
        int result = 0;
        for (int i = 1; i < month ; i ++)
            result += m[i] * 24 * 60;
        result += day * 24 * 60;
        result += hour * 60;
        result += minute;
        //System.err.println("Result = " + result);
        return result;
    }
    
    
    BufferedReader bf;
    StringTokenizer st;
    PrintWriter out;
    
    public String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(bf.readLine());
        return st.nextToken();
    }
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    
    public Main() throws IOException {
        bf = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        solve();
        bf.close();
        out.close();
    }
    
    public static void main(String args[]) throws IOException {
        new Main();
    }
    
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
        
    }
}








