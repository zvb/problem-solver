import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
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
        //in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        //out = new PrintWriter(new OutputStreamWriter(System.out));

        solve();
        out.close();
    }
    

    public void solve() throws Exception {
        int T = nextInt();
        for (int t = 1 ; t <= T ; t ++)
            solveT(t);
    }

    public void solveT(int t) throws Exception {
        String s = next();
        out.print(String.format("Case #%d: ", t));
        out.println(rec(s, s.length(), 'Z'));
    }

    public String rec(String s, int r, char st) {
        if (r == 0)
            return "";
        StringBuilder sb = new StringBuilder();
        for (char c = st ; c >= 'A' ; c --) {
            int idx = s.substring(0, r).indexOf(c);

            if (idx < 0)
                continue;
            //out.println("idx = " + idx);
            for (int i = idx ; i < r ; i++) {
                if (s.charAt(i) == c)
                    sb.append(c);
            }
            String res = rec(s, idx, (char)(c-1));
            sb.append(res);
            for (int i = idx ; i < r ; i++) {
                if (s.charAt(i) != c)
                    sb.append(s.charAt(i));
            }
            break;
        }
        return sb.toString();
    }

}
