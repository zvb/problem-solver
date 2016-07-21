import java.io.*;
import java.util.*;

public class Main {


    public void solve() throws IOException {
        int n = nextInt();
        String directions = next();
        int x[] = new int [n];
        for (int i = 0 ; i < n ; i++) {
            x[i] = nextInt();
        }
        int ans = 1 << 30;
        for (int i = 0 ; i + 2 <= n ; i ++) {
            String two = directions.substring(i, i+2);
            if (two.equals("RL") ) {
                int delta = Math.abs(x[i] - x[i+1]) / 2;
                ans = Math.min(delta, ans);
            }
        }
        out.println( (ans < (1 << 30) ? ans : -1));
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