import java.io.*;
import java.util.*;

public class Main {
    
    public final static int MOD = (int)(1e9);
    
    int n, k, a[], dp[][];
    public void solve() throws IOException {
        n = nextInt(); k = nextInt();
        a = new int [n + 1];
        for (int i = 1; i <= n ; i ++) {
            a[i] = nextInt();
        }
        BIT bit;
        dp = new int [k + 1][n + 1]; // dp[k][n] number of inversions with length k and ending at n
        for (int i = 1 ; i <= k ; i ++) {
            if (i == 1) {
                for (int j = 1 ; j <= n ; j ++) {
                    dp[i][j] = 1;
                }
                continue;
            }
            bit = new BIT(n);
            
            for (int j = 1 ; j <= n ; j ++) {
                dp[i][j] = bit.getSum(a[j] + 1, n);
                bit.addValue(a[j], dp[i-1][j]);
                //System.err.print(dp[i][j] + " ");
            }
            //System.err.println();
        }
        int ans = 0;
        for (int i = 1 ; i <= n ; i ++) {
            ans += dp[k][i];
            if (ans >= MOD)
                ans -= MOD;
        }
        out.println(ans);
        
    }
    
    public class BIT {
        final int N;
        private int a[];
        public BIT(int n) {
            N = n;
            a = new int [n + 1];
        }
        public void addValue(int x, int val) {
            while (x <= N) {
                a[x] += val;
                if (a[x] >= MOD) a[x] -= MOD;
                x += x & -x;
            }
        }
        public int getSum(int l, int r) {
            if (l > r) return 0;
            return ((get(r) - get(l - 1))%MOD + MOD)%MOD;
        }
        private int get(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += a[idx];
                if (sum >= MOD) sum -= MOD;
                idx -= (idx & -idx);
            }
            return sum;
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