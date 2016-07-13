import java.io.*;
import java.util.*;

public class Main {

    public void solveTestCase(int t) throws IOException {
        int m = nextInt();
        String s = next();
        int n = s.length();
        int [] a = new int [n];
        for (int i = 0 ; i < n ; i ++) {
            a[i] = s.charAt(i) - '0';
        }
        int ans = 0, cur = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (cur >= i) {
                cur += a[i];
                //out.println("i=" + i + " cur = " + cur);
            } else {
                ans += i - cur;
                //out.println("i=" + i + " cur = " + cur);
                cur = i + a[i];

            }
        }
        out.println(String.format("Case #%d: %d", t + 1, ans));
    }

    public void solve() throws IOException {
        int T = nextInt();
        for (int i = 0 ; i < T ; i ++)
            solveTestCase(i);
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