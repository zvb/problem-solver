import java.io.*;
import java.util.*;

public class Main {


    public final static int CONTEST = 1, GYM = 1 << 1, INF = 1 << 30;
    public void solve() throws IOException {
        int n = nextInt();
        int a[] = new int[n];
        for (int i = 0 ; i < n ; i++) 
            a[i] = nextInt();

        int dp[][] = new int[3][n];

        for (int i = 0 ; i < n ; i++) {
            int prevIfGym = i > 0 ? dp[GYM][i-1] : 0;
            int prevIfCon = i > 0 ? dp[CONTEST][i-1] : 0;
            int prevIfNon = i > 0 ? dp[0][i-1] : 0;

            if ( (a[i] & CONTEST) > 0) {
                dp[CONTEST][i] = Math.max(prevIfGym, prevIfNon) + 1;
            }

            if ( (a[i] & GYM) > 0 ) {
                dp[GYM][i] = Math.max(prevIfCon, prevIfNon) + 1;
            }

            dp[0][i] = Math.max(prevIfCon, prevIfGym);
            if (dp[0][i] < prevIfNon)
                dp[0][i] = prevIfNon;

            //out.println(dp[0][i] + " " + dp[1][i] + " " + dp[2][i]);
        }

        int best = 0;
        for( int k = 0 ; k < 3 ; k ++) {
            best = Math.max(dp[k][n-1], best);
        }
        out.println(n - best);
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
    
    public long nextLong() throws IOException {
        return Long.parseLong(next());
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