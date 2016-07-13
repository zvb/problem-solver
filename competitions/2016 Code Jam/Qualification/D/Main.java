import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.lang.Integer;
import java.lang.String;
import java.lang.StringBuilder;
import java.util.*;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        Main mainClass = new Main();
    }

    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    // This just returns next token from the input stream
    public String next() throws Exception {
        if (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws Exception {
        return Integer.parseInt(next());
    }

    public double nextDouble() throws Exception {
        return Double.parseDouble(next());
    }

    public long nextLong() throws Exception {
        return Long.parseLong(next());
    }

    public Main() throws Exception {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));

        solve();
        out.close();
    }
    

    public void solve() throws Exception {
        sim(nextInt(), nextInt());
    }

    public void sim(int K, int C) {
        long N = 1; // K^C
        for (int i = 0 ; i < C ; i++) {
            N = N * K;
        }
        // Contains indices r[i] = list of tail indices that reveal that ith position is G in the
        // original tail
        LinkedHashSet<Integer> [] r = new LinkedHashSet[K];

        for (int i = 0 ; i < K ; i ++) {
            // Simulating word with all L's except the ith which is G
            char [] str = new char[K];
            for (int j = 0 ; j < str.length; j++) {
                str[j] = (i == j ? '1' : '0');
            }
            String w = new String(str);
            for (int t = 1 ; t < C ;t ++) {
                w = expand(w);
            }
            r[i] = new LinkedHashSet<>();
            for (int j = 0 ; j < w.length(); j++) {
                if (w.charAt(j) == '1') {
                    r[i].add(j);
                }
            }
            out.println("Word : " + str);
            out.println(r[i]);
            out.println();
        }
    }

    String expand(String w) {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0 ; i < w.length(); i++) {
            if (w.charAt(i) == '0') {
                stringBuilder.append(w);
            } else {
                for (int j=0; j < w.length(); j++) {
                    stringBuilder.append('1');
                }
            }
        }
        return stringBuilder.toString();
    }

}
