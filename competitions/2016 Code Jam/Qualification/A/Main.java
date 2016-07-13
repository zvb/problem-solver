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
            solveTest(nextInt(), i);
        }
    }

    public void solveTest(int n, int testNum) throws Exception {
        if (n == 0) {
            out.println(String.format("Case #%d: INSOMNIA", testNum));
            return;
        }

        long res = findStupid(n);
        if (res < 0)
            throw new Exception("Could not solve for " + n);
        //out.println("Here " + res);
        out.println(String.format("Case #%d: %d", testNum, res));
    }

    long findStupid(int n) {

        int mask = 0;
        for (int i = 1 ; i < 1000; i++) {
            long current = 1L * i * n;
            while (current > 0) {
                int lastDigit = (int)(current % 10);
                mask |= 1 << lastDigit;
                current /= 10;
            }
            if (Integer.bitCount(mask) == 10)
                return 1L * i * n;
        }
        //out.print("Could not find for " + n);
        return -1;
    }

}
