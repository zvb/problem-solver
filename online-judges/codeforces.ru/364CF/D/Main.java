import java.io.*;
import java.util.*;

public class Main {


    
    public void solve() throws IOException {
        int n = nextInt();
        int l = nextInt();
        int v1 = nextInt(), v2 = nextInt();
        int k = nextInt();

        int p = (n + k - 1)/k;

        double c = p + 1.0 * (p-1) * (v2 - v1) / (v2 + v1) - 1.0;
        double t2 = 1.0 * l / (v1 * c + v2);
        double t1 = c * t2;

        double ans = Math.min(1.0 * l/v1, t1 + t2);
        out.println(String.format("%.12f", ans));
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