import java.io.*;
import java.util.*;

public class Main {

    ArrayList<ArrayList<Integer> > g; 
    Set<Integer> u;

    int dp[];
    void dfs(int v, int p) {
        
        for (int to : g.get(v)) {
            if (to != p) {
                dfs(to, v);
                dp[v] += dp[to];
            }
        }
        dp[v] += (u.contains(v) ? 1 : 0);
        
    }

    long total = 0;

    void dfs2(int v, int p, int k) {

        for (int to : g.get(v)) {
            if (to != p) {
                int d = Math.min(dp[to], 2*k - dp[to]);
                //out.println("v = " + v + " to = " + to + " d = " + d);
                total += d;
                dfs2(to, v, k);        
            }
        }
        
    }
    
    public void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        u = new HashSet<Integer>();
        for (int i = 0 ; i < 2*k ; i++) {
            u.add(nextInt()-1);
        }

        g = new ArrayList<ArrayList<Integer> > ();
        for (int i = 0 ; i < n ; i++) {
            g.add(new ArrayList<Integer>());
        }


        dp = new int[n];
        for (int i = 1; i < n ; i++) {
            int x = nextInt(), y = nextInt();
            x --; y --;
            g.get(x).add(y);
            g.get(y).add(x);
        }

        dfs(0, -1);
        dfs2(0, -1, k);
        //out.println(Arrays.toString(dp));
        out.println(total);




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