import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.lang.*;
import java.lang.Exception;
import java.lang.Integer;
import java.lang.String;
import java.lang.StringBuilder;
import java.lang.System;
import java.util.*;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedHashMap;
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
        int t = nextInt();
        int n = nextInt(), j = nextInt();
        for (int i = 1 ; i <= t ; i++) {
            solveTest(i, n, j);
        }
    }

    ArrayList<String> generateTemplates(int maxLen) {
        // Assuming maxLen >= 2
        maxLen -= 2;
        ArrayList<String> result = new ArrayList<>();
        result.add("11");
        for (long mask = 0 ; mask < (1L << maxLen) ; mask ++) {
            String template = "1" + Long.toBinaryString(mask) + "1";
            result.add(template);
        }
        return result;
    }

    public void solveTest(int testNum, int n, int j) throws Exception {

        out.println(String.format("Case #%d:", testNum));

        ArrayList<String> templates = generateTemplates(n / 2);
        LinkedHashMap<String, ArrayList<Long> > ans = new LinkedHashMap<>();

        for (String t : templates) {
            //out.println("working with " + t);


            int remLen = n - t.length() * 2;
            int bitCount = remLen / t.length();


            for (int mask = 0 ; mask < (1 << bitCount) ; mask++) {
                StringBuilder stringBuilder = new StringBuilder();
                stringBuilder.append(t);


                int paddingZeros = remLen % t.length();


                //out.println("rem length " + remLen);

                while (paddingZeros > 0) {
                    stringBuilder.append('0');
                    paddingZeros --;
                }

                for (int i = 0 ; i < bitCount ; i++) {
                    if ( (mask & (1 << i)) > 0 ) {
                        stringBuilder.append(t);
                    } else {
                        for (int k = 0; k < t.length(); k++)
                            stringBuilder.append('0');
                    }
                }
                stringBuilder.append(t);
                ArrayList<Long> divisors = new ArrayList<>();

                for (int i = 2 ; i <= 10; i++) {
                    divisors.add(Long.valueOf(t, i));
                }

                String l = stringBuilder.toString();
//                if (l.length() != n)
//                    out.println("Not correct " + l);
                ans.put(l, divisors);
            }


        }
        //out.println(ans.size());
        for (Map.Entry<String, ArrayList<Long> > e : ans.entrySet()) {
            if (j <= 0)
                break;
            j--;

            out.print(e.getKey());
            for (Long div : e.getValue()) {
                out.print(" " + div);
            }
            out.println();
        }

    }

}
