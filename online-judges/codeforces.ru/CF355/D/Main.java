import java.io.*;
import java.util.*;

public class Main {

    final static int INF = 1 << 30;

    static class Pair implements Comparable<Pair> {
        int i, j;
        int dist;
        public int compareTo(Pair o) {
            if (dist != o.dist)
                return dist - o.dist;
            return i == o.i ? j - o.j : i - o.i;
        }
        Pair(int _i, int _j) {
            i = _i; j = _j;
        }
        Pair(int _i, int _j, int _dist) {
            i = _i; j = _j; dist = _dist;
        }
        int distTo(Pair o) {
            return Math.abs(i - o.i) + Math.abs(j - o.j);
        }
    }

    final int dx[] = new int[] {1, 0, -1,  0};
    final int dy[] = new int[] {0, 1,  0, -1};

    void compute(int n, int m, ArrayList<Pair> first, ArrayList<Pair> second) {
        // moving from first to second;
        //out.println("Going bfs")

        if (1L * first.size() * second.size() > 1L * n * m * (int)Math.sqrt(m*n) {
            int best[][] = new int[n][m];
            for (int i = 0 ; i < n ; i ++) {
                Arrays.fill(best[i], INF);
            }

            PriorityQueue<Pair> queue = new PriorityQueue<Pair>();
            for (Pair f : first) {
                best[f.i][f.j] = f.dist;
                queue.add(f);
            }

            while (!queue.isEmpty()) {
                Pair current = queue.poll();
                if (best[current.i][current.j] != current.dist) 
                    continue;

                for (int k = 0 ; k < 4 ; k ++) {
                    int ni = current.i + dx[k], nj = current.j + dy[k];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && best[ni][nj] > current.dist + 1) {
                        best[ni][nj] = current.dist + 1;
                        queue.add(new Pair(ni, nj, current.dist+1));
                    }
                }
                
            }

            for (Pair s : second) {
                s.dist = best[s.i][s.j];
            }



            
        } else {
            for (Pair s : second) {
                Pair best = first.get(0);

                for (int i = 1 ; i < first.size() ; i ++) {
                    Pair target = first.get(i);
                    if (s.distTo(best) + best.dist > s.distTo(target) + target.dist)
                        best = target;
                }
                s.dist = s.distTo(best) + best.dist;
            }

        }
    }
    ArrayList< ArrayList<Pair> > idx;


    int a[][];
    int dp[][];



    public void solve() throws IOException {
        int n = nextInt(), m = nextInt(), p = nextInt();
        a = new int[n][m];
        dp = new int[n][m];

        idx = new ArrayList< ArrayList<Pair> >();
        for (int i = 0 ; i < p ; i ++) 
            idx.add(new ArrayList<Pair>());


        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                a[i][j] = nextInt()-1;
                idx.get(a[i][j]).add(new Pair(i, j));
            }
        }   

        ArrayList<Pair> first = idx.get(0);
        for (Pair f: first) {
            f.dist = f.i + f.j;
        }
        for (int pp = 1 ; pp < p ; pp++) {
            compute(n,m, idx.get(pp-1), idx.get(pp));
        }

        out.println(idx.get(p-1).get(0).dist);
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