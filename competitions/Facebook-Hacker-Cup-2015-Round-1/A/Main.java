import java.io.*;
import java.util.*;

public class Main {
    
    final int N = (int)1e7 + 1;
    
    boolean sieve[];
    int [] p;
    HashMap<Integer, ArrayList<Integer> > pr;
    
    public void solve() throws IOException {
        sieve = new boolean [N];
        p = new int [N];
        pr = new HashMap<Integer, ArrayList<Integer> >();
        sieve[1] = true;
        for (int i = 2 ; i < N ; i ++) {
            if (!sieve[i]) {
                p[i] = 1;
                for (int j = i + i; j < N ; j += i) {
                    sieve[j] = true;
                    p[j] ++;
                }
            }
        }
        
        for (int i = 1 ; i < N ; i ++) {
            if (pr.containsKey(p[i])) {
                
            } else {
                pr.put(p[i], new ArrayList<Integer>());
            }
            pr.get(p[i]).add(i);
        }
        int T = nextInt();
        for (int t = 1; t <= T ; t ++) {
            int A = nextInt(), B = nextInt();
            int K = nextInt();
            out.println(String.format("Case #%d: %d", t, getPos(K, B) - getPos(K, A-1)));
        }
        
    }
    //0 1 1 1 1 2 1 1 1 2 1 2 1 2 2 1 1 2 1 2 2 2 1 2 1 2 1 2 1 3 1 1 2
    int getPos(int K, int A) {
        ArrayList<Integer> list = pr.get(K);
        if (list == null) return 0;
        int lo = 0, hi = list.size(), mid;
        while (hi > lo) {
            mid = lo + (hi - lo) / 2;
            if (list.get(mid) <= A)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
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
