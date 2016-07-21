import java.io.*;
import java.util.*;

public class Main {

    public final static int C = 6, MOD = (int)1e9 + 7;

    int p3[] = new int[10];

    int getNum(int mask) {
        return p3[C - Integer.bitCount(mask)];
    }
    int convert(char c) {
        if (Character.isDigit(c)) {
            return c - '0';
        } else if (Character.isUpperCase(c)) {
            return 10 + c - 'A';
        } else if (Character.isLowerCase(c)) {
            return 36 + c - 'a';
        }
        return c == '-' ? 62 : 63;
    }
    public void solve() throws IOException {
        p3[0] = 1;
        for (int i = 1 ; i < 10 ; i++) {
            p3[i] = (p3[i-1] * 3) % MOD;
        }

        String s = next();
        long res = 1;
        for (int i = 0 ; i < s.length() ; i++) {
            char c = s.charAt(i);
            int m = convert(c);
            res = (1L * res * getNum(m)) % MOD;
        }
        out.println(res);
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