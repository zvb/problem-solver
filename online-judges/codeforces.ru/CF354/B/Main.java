import java.io.*;
import java.util.*;

public class Main {


    public void solve() throws IOException {
        int n = nextInt(), t = nextInt();
        double dp[][] = new double[n+1][n+1];
        double f[][] = new double[n+1][n+1];
        boolean filled[][]= new boolean[n+1][n+1];

        filled[0][0] = true;
        f[0][0] = 1.0;

        filled[0][1] = true;
        f[0][1] = 1.0;
        
        while (t-- > 0) {
            for (int i = 1 ; i <= n ; i ++) {
                for (int j = 1 ; j <= i ; j++) {
                    if (filled[i][j]) {
                        f[i][j] = f[i-1][j-1] / 2 + f[i-1][j] / 2;
                    } else {
                        // if left upper is filled
                        if (filled[i-1][j-1]) {
                            dp[i][j] += f[i-1][j-1]/2;
                        }

                        if (filled[i-1][j]) {
                            dp[i][j] += f[i-1][j]/2;
                        }
                        if (dp[i][j] >= 1.0) {
                            filled[i][j] = true;
                            f[i][j] = dp[i][j] - 1.0;
                            dp[i][j] = 1.0;
                        }
                    }
                    //out.print(dp[i][j] + " ");
                }
                //out.println();
            }    
        }

        int ans = 0;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= i ; j++) {
                if (filled[i][j])
                    ans ++;
            }
        }
        out.println(ans);
        
        
        
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
