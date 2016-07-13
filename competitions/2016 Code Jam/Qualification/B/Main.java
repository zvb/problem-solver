import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.lang.Exception;
import java.lang.Integer;
import java.lang.System;
import java.util.StringTokenizer;
import java.util.LinkedHashMap;
import java.util.ArrayList;
import java.util.Collections;

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
        int t = nextInt();
        for (int i = 1 ; i <= t ; i++) {
            solveTest(i, next());
        }
    }

    public void solveTest(int testNum, String s) throws Exception {
        s = s + '+';
        final String p = "+-", q = "-+";
        int ans = 0;
        for (int i = 0 ; i + 1 < s.length() ; i++) {
            String x = s.substring(i, i + 2);
            if (x.equals(p) || x.equals(q))
                ans ++;
        }
        out.println(String.format("Case #%d: %d", testNum, ans));
    }

}
