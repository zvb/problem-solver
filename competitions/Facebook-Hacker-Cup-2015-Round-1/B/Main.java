import java.io.*;
import java.util.*;

public class Main {
    final static int MOD = (int)1e9 + 7;
    int T;
    int dp[][];
    int df[][];
    public void solve() throws IOException {
        T = nextInt();
        for (int i = 1 ; i <= T ; i ++) {
            find(i);
        }
    }
    public void find(int t) throws IOException {
        String s = next();
        int l = s.indexOf('-');
        int n = Integer.parseInt(s.substring(0, l));
        int m = Integer.parseInt(s.substring(l + 1));
        dp = new int [n+5][m+5];
        df = new int[n+5][m+5];
        dp[1][0] = 1;
        for (int i = 0 ; i <= n ; i ++) {
            for (int j = 0 ; j < i && j <= m ; j ++) {
                if (i > j + 1) {
                    dp[i][j+1] += dp[i][j];
                    if (dp[i][j+1] >= MOD) dp[i][j+1] -= MOD;
                }
                dp[i+1][j] += dp[i][j];
                if (dp[i+1][j] >= MOD)
                    dp[i+1][j] -= MOD;
            }
        }
        df[0][0] = 1;
        for (int j = 0 ; j <= m ; j ++) {
            for (int i = 0 ; i <= j ; i ++) {
                if (i < j) {
                    df[i+1][j] += df[i][j];
                    if (df[i+1][j] >= MOD)
                        df[i+1][j] -= MOD;
                }
                df[i][j+1] += df[i][j];
                if (df[i][j+1] >= MOD)
                    df[i][j+1] -= MOD;
            }
        }
        out.println(String.format("Case #%d: %d %d", t, dp[n][m], df[m][m]));
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