import java.io.*;
import java.util.*;

public class Main {


    public static class StringHasher {
        public final static int p = 257;

        long p2[], hashSums[];
        public StringHasher(String s) {
            int n = s.length();
            p2 = new long[n+1];
            for (int i = 0 ; i <= n ; i++) {
                p2[i] = i > 0 ? p2[i-1] * p : 1L;
            }

            hashSums = new long[n];

            for (int i = 0 ; i < n ; i ++) {
                hashSums[i] = (i > 0 ? hashSums[i-1] : 0L) + s.charAt(i) * p2[i];
            }
        }

        public long getSubstringHash(int beginIndex, int endIndex) {
            int n = hashSums.length;
            long multiplier = p2[n - beginIndex];

            long result = 0;
            if (endIndex > 0)
                result += hashSums[endIndex-1];

            if (beginIndex > 0)
                result -= hashSums[beginIndex-1];

            return multiplier * result;
        }
        public long getHash(String s) {
            long result = 0;
            for (int i = 0 ; i < s.length() ; i++) {
                result += s.charAt(i) * p2[i];
            }
            return result * p2[hashSums.length];
        }
    }

    public void solve() throws IOException {
        String s = next(), t = next();
        if (s.length() < t.length()) {
            return;
        }
        StringHasher h = new StringHasher(s);

        int tLen = t.length();
        long tHash = h.getHash(t);
        for (int i = 0 ; i + tLen <= s.length(); i++) {
            if (h.getSubstringHash(i, i + tLen) == tHash) 
                out.print(i + " ");
        }
        out.println();
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