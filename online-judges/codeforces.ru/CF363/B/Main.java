import java.io.*;
import java.util.*;

public class Main {


    public void solve() throws IOException {
        int n = nextInt(), m = nextInt();
        char g[][] = new char[n+2][m+2];


        int total = 0;

        for (int i = 1 ; i <= n ; i++) {
            String line = next();
            for (int j = 0 ; j < m ; j++) {
                char c = line.charAt(j);
                g[i][j+1] = c;
                if (c == '*')
                    total ++;
            }
        }

        int up[][] = new int[n+2][m+2];
        int down[][] = new int[n+2][m+2];
        int left[][] = new int[n+2][m+2];
        int right[][] = new int[n+2][m+2];

        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j<= m ; j++) {
                up[i][j] = up[i-1][j] + (g[i][j] == '*' ? 1 : 0);
                left[i][j] = left[i][j-1] + (g[i][j] == '*' ? 1 : 0);
            }
        }

        for (int i = n ; i >= 1 ; i --) {
            for (int j = m ; j >= 1 ; j --) {
                down[i][j] = down[i+1][j] + (g[i][j] == '*' ? 1 : 0);
                right[i][j] = right[i][j+1] + (g[i][j] == '*' ? 1 : 0);
            }
        }

        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1;  j<= m ; j++) {
                int covers = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                if (g[i][j] == '*')
                    covers -= 3;

                if (covers == total) {
                    out.println("YES");
                    out.println(i + " " + j);
                    return;
                }
            }
        }
        out.println("NO");
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