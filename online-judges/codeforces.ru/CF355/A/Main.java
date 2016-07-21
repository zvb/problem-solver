import java.io.*;
import java.util.*;

public class Main {


    public void solve() throws IOException {
        int n = nextInt(), h = nextInt();
        int ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            int a = nextInt();
            if (a > h)
                ans += 2;
            else 
                ans ++;
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