import java.io.*;
import java.util.*;

public class Main {

    public final static int MOD = (int)1e9 + 7;
    int n;
    int a[][];
    int l[][];
    int r[][];
    int u[][];
    int d[][];

    double colSum[][];
    double rowSum[][];
    double diagRes = 0.0;

    public long solveDiag() {
        int lu[][] = new int[n+2][n+2];
        int ru[][] = new int[n+2][n+2];
        int ld[][] = new int[n+2][n+2];
        int rd[][] = new int[n+2][n+2];

        for (int i = 1;  i <= n ; i++) {
            for (int j = 1; j <= n ; j++) {
                if (a[i][j] == 0)
                    lu[i][j] = 0;
                else
                    lu[i][j] = lu[i-1][j-1] + 1;
            }
        }

        for (int i = 1;  i <= n ; i++) {
            for (int j = n; j >= 1 ; j--) {
                if (a[i][j] == 0)
                    ru[i][j] = 0;
                else
                    ru[i][j] = ru[i-1][j+1] + 1;
            }
        }
        for (int i = n; i >= 1 ; i--) {
            for (int j = 1; j <= n ; j++) {
                if (a[i][j] == 0)
                    ld[i][j] = 0;
                else
                    ld[i][j] = ld[i+1][j-1] + 1;
            }
        }
        for (int i = n; i >= 1 ; i--) {
            for (int j = n; j >= 1 ; j--) {
                if (a[i][j] == 0)
                    rd[i][j] = 0;
                else 
                    rd[i][j] = rd[i+1][j+1] + 1;
            }
        }

 

        double luSum[][] = new double[n+1][n+1];
        for (int i = 1;  i <= n ; i ++) {
            for (int j = 1; j <= n ; j++) {
                luSum[i][j] = luSum[i-1][j-1] + (a[i][j] > 0 ? Math.log(a[i][j]) : 0.0);
            }
        }

        double ruSum[][] = new double[n+2][n+2];
        for (int i = 1;  i <= n ; i ++) {
            for (int j = n; j >= 1 ; j--) {
                ruSum[i][j] = ruSum[i-1][j+1] + (a[i][j] > 0 ? Math.log(a[i][j]) : 0.0);
            }
        }

        int best_i = -1, best_j = -1, best_d = -1;
        double best = 0.0;

        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= n ; j++) {
                if (a[i][j] == 0)
                    continue;

                int md = Math.min(Math.min(lu[i][j], ru[i][j]), Math.min(ld[i][j], rd[i][j]));

                double mainDiagSum = luSum[i + md-1][j+md-1] - luSum[i-md][j-md];
                double subDiagSum  = ruSum[i+md-1][j-md+1] - ruSum[i-md][j+md];

                double total = mainDiagSum + subDiagSum - Math.log(a[i][j]);
                if (best_i == -1 || total > best) {
                    best = total;
                    best_i = i;
                    best_j = j;
                    best_d = md;
                }

            }
        }
        diagRes = best;
        //out.println("solve diag " + best_i + "," + best_j + " " + best_d);

        long res = 1;
        for (int curI = best_i - best_d + 1, curJ = best_j - best_d + 1; curI < best_i + best_d; curI++, curJ++) {
            if (curI != best_i)
                res = (res * a[curI][curJ]) % MOD;
        }

        for (int curI = best_i - best_d + 1, curJ = best_j + best_d - 1; curI < best_i + best_d; curI++, curJ--) {
            res = (res * a[curI][curJ]) % MOD;
        }

        return res;

    }
    public void solve() throws IOException {
        n = nextInt();

        a = new int[n+1][n+1];
        l = new int[n+2][n+2];
        r = new int[n+2][n+2];
        u = new int[n+2][n+2];
        d = new int[n+2][n+2];
        colSum = new double[n+1][n+1];
        rowSum = new double[n+1][n+1];



        for (int i = 1 ; i <= n ; i++) {
            String s = next();
            for (int j = 1 ; j <= n ; j++) {
                a[i][j] = s.charAt(j-1) - '0';
            }
        }

        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                rowSum[i][j] = rowSum[i][j-1] + (a[i][j] == 0 ? 0.0 : Math.log(a[i][j]));
                colSum[j][i] = colSum[j][i-1] + (a[i][j] == 0 ? 0.0 : Math.log(a[i][j]));
            }
        }

        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= n ; j ++) {
                if (a[i][j] == 0) {
                    l[i][j] = 0;
                    u[i][j] = 0;
                } else {
                    l[i][j] = l[i][j-1] + 1;
                    u[i][j] = u[i-1][j] + 1;
                }
            }

            for (int j = n ; j >= 1 ; j --) {
                if (a[i][j] == 0) {
                    r[i][j] = 0;
                    
                } else {
                    r[i][j] = r[i][j+1] + 1;
                    
                }
                if (a[j][i] == 0)
                    d[j][i] = 0;
                else
                    d[j][i] = d[j+1][i] + 1;
                
            }
        }

        
        int best_i = -1, best_j = -1, best_d = -1;
        double best = 0.0;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                if (a[i][j] == 0)
                    continue;

                int md = Math.min(Math.min(u[i][j], d[i][j]), Math.min(l[i][j], r[i][j]));
                //out.println("i, j = " + i + ", " + j + " " + md);
                double[] row = rowSum[i];
                double[] col = colSum[j];

                double leftSum = row[j] - row[j-md];
                double rightSum = row[j+md-1] - row[j-1];

                double topSum = col[i] - col[i-md];
                double botSum = col[i+md-1] - col[i-1];

                double total = leftSum + rightSum + botSum + topSum - 3 * Math.log(a[i][j]);
                if (best_j == -1 || total > best) {
                    best_i = i; best_j = j; best_d = md;
                    best = total;
                }
            }
        }
        if (best_d == -1) {
            out.println("0");
            return ;
        }

        long res = 1;

    
        for (int i = best_i - best_d + 1; i < best_i + best_d; i++) {
            if (i != best_i)
                res = (res * a[i][best_j]) % MOD;
        }

        for (int j = best_j - best_d + 1; j < best_j + best_d; j++) {
            res = (res * a[best_i][j]) % MOD;
        }

            


        
        long diagAns = solveDiag();
        if (diagRes < best)
            out.println(res);
        else
            out.println(diagAns);

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