import java.io.*;
import java.util.*;

public class Main {


    void change(int [] all, char c, int val) {
        if (Character.isUpperCase(c))
            all[c - 'A' + 26] += val;
        else
            all[c - 'a'] += val;
    }

    int countDistinct(int [] a) {
        int res = 0;
        for (int i = 0 ; i< a.length ; i++) {
            if (a[i] > 0)
                res ++;
        }
        return res;
    }
    public void solve() throws IOException {
        int n = nextInt();
        String s = next();

        int [] all = new int[52];
        for (int i = 0 ; i < s.length() ; i++) {
            char c = s.charAt(i);
            change(all, c, 1);
        }
        int distinct = countDistinct(all);

        int [] window = new int[52];
        int best = n;
        for (int i = 0, j = 0 ; i < s.length() ; i++) {

            if (i > 0) {
                change(window, s.charAt(i-1), -1);
            }
            while (j < s.length()) {
                if (countDistinct(window) == distinct)
                    break;

                change(window, s.charAt(j), 1);
                j ++;
            }
            if (countDistinct(window) < distinct)
                break;

            best = Math.min(best, j - i);
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