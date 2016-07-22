import java.io.*;
import java.util.*;

public class Main {

    public static class StringHasher {
        public final static int p = 257;


        private long [] hashSums;
        private long [] p2;


        public StringHasher(String s) {
            int n = s.length();
            hashSums = new long[n];
            p2 = new long [n+1];

            for (int i = 0 ; i <= n ; i++)
                p2[i] = i > 0 ? p2[i-1] * p : 1L;

            for (int i = 0 ; i < n ; i++) {
                hashSums[i] = (i > 0 ? hashSums[i-1] : 0L) + s.charAt(i) * p2[i];
            }
        }

        public long getHash(int beginIndex, int endIndex) {
            // check beginIndex >= 0, endIndex <= n
            int n = hashSums.length;
            long multiplier = p2[n-beginIndex];
            long result = 0;

            if (endIndex > 0)
                result += hashSums[endIndex-1];

            if (beginIndex > 0) 
                result -= hashSums[beginIndex-1];

            return result * multiplier;
        }
    }

    public void solve() throws IOException {
        String s = next();
        StringHasher h = new StringHasher(s);

        int n = s.length();

        for (int len = 1 ; len <= n ; len ++) {
            boolean good = true;

            for (int start = len; start < n ; start += len) {

                int end = Math.min(start + len, n);

                //out.println("start = " + start + " end = " + end);

                long targetHash = h.getHash(0, end - start);
                long hash = h.getHash(start, end);

                //out.println("Len = " + len + " , target = " + targetHash + " actual = " + hash);
                if (targetHash != hash) {
                    good = false;
                    break;
                }
            }
            if (good) {
                out.println(len);
                return;
            }
        }
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