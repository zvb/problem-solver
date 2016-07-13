
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.*;

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
    int [][] a;
    int N;
    public void solveT(int t) throws Exception {
        N = nextInt();
        a = new int [2*N+2][];
        out.print(String.format("Case #%d: ", t));
        for (int i = 1 ; i <= 2*N - 1 ; i++) {
            a[i] = new int[N+1];
            for (int j = 1 ; j <= N; j++)
                a[i][j] = nextInt();
        }
        int bad = -1;
        TreeSet<Integer> excl = new TreeSet<>();

        for (int i = 1 ; i <= N ; i++) {
            Result res = getMin(i, excl);
            if (res.count == 1) {
                int idx = res.idx.first();
                //out.println("found missing " + res.val);
                //out.println("idx = " + idx);
                ArrayList<Integer> ans = new ArrayList<>();
                int [] no = new int[3000];

                for (int j = 1 ; j <= 2*N - 1 ; j++) {
                    no[a[j][i]] ++;
                }
                for (int j = 1 ; j <= N; j++)
                    no[a[idx][j]] --;

                //out.println( "no = " + no);
                no[a[idx][i]] ++;
                for (int k = 0 ; k < no.length ; k++) {
                    if (no[k] > 0)
                        out.print(k + " ");
                }
                out.println();
                return;
            } else if (res.count == 2) {
                excl.addAll(res.idx);
                continue;
            } else {
                throw new Exception("Error here " + i + " " + res.val);
            }
        }



    }
    Result getMin(int pos, TreeSet<Integer> excl) {
        int min = 1 << 30;
        for (int i = 1 ; i <= 2 * N - 1 ; i++) {
            if (!excl.contains(i))
                min = Math.min(a[i][pos], min);
        }
        int count = 0;
        Result res = new Result();
        res.idx = new TreeSet<>();
        for (int i = 1 ; i <= 2 * N - 1 ; i++) {
            if (a[i][pos] == min) {
                count++;
                res.idx.add(i);
            }
        }


        res.val = min;
        res.count = count;

        return res;
    }

    class Result {
        int val, count;
        TreeSet<Integer> idx;
    }



}
