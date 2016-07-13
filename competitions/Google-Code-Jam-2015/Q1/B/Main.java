import java.io.*;
import java.util.*;

public class Main {

    public void solveTest(int t) throws IOException {
        int n = nextInt();
        int [] a = new int [n];
        for (int i = 0 ; i < n ; i ++) 
            a[i] = nextInt();
        final int N_MAX = 1000;
        int best = Integer.MAX_VALUE;
        for (int i = 1 ; i <= N_MAX ; i++) {
            int special = 0;
            for (int j = 0 ; j < n ; j ++) {
                if (a[j] > i) {
                    special += (a[j] + i - 1) / i - 1;
                }
            }
            best = Math.min(best, i + special);
        }
        out.println(String.format("Case #%d: %d", t, best));
    }
    public void solve() throws IOException {
        int T = nextInt();
        for (int i = 1 ; i <= T ;i ++) {
            solveTest(i);
        }
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
}