import java.io.*;
import java.util.*;

public class Main {


    public void solve() throws IOException {
        int n = nextInt(), k = nextInt();
        String s = next();
        // assume our longest substring begins with 'a'. Check how long it can be for given i
        int e = 0;
        int available = k;
        int best = 1;
        for (int i = 0 ; i < s.length() ; i++) {
            if (i > 0 && s.charAt(i-1) == 'b')
                available ++;

            while (e + 1 <= s.length() && available >= 0) {
                if (s.charAt(e) == 'b') {
                    if (available == 0)
                        break;
                    available --;
                }
                    

                e ++;
            }
            best = Math.max(best, e - i);
        }

        available = k;
        e = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            if (i > 0 && s.charAt(i-1) == 'a')
                available ++;

            while (e + 1 <= s.length() && available >= 0) {
                if (s.charAt(e) == 'a') {
                    if (available == 0)
                        break;
                    available --;
                }
                    

                e ++;
            }
            best = Math.max(best, e - i);
        }

        out.println(best);
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
