import java.io.*;
import java.util.*;

public class Main {


    public void solve() throws IOException {
        int n = nextInt();
        int []p = new int[n+1];
        int []q = new int[n+1];
        for (int i = 1 ; i <= n ; i++) {
            p[i] = nextInt();
            q[i] = p[i];
        }

        int col[] = new int[n+1];

        int root = -1;
        for (int i = 1 ; i <= n ; i++) {
            if (p[i] == i) {
                root = i;
                col[root] = 2;
                break;
            }
        }

        for (int i = 1 ; i <= n ; i++) {
            if (col[i] == 2) 
                continue;

            boolean cycle = false;
            int current = i;
            while (true) {
                col[current] = 1;

                int parent = p[current];
                if (col[parent] == 1) {
                    // cycle
                    if (root == -1)
                        root = current;

                    q[current] = root;
                    cycle = true;
                    // Mark as good
                    col[current] = 2;
                    break;
                    
                } else if (col[parent] == 2) {
                    break;
                }
                current = parent;
            }
            current = i;
            while (col[current] != 2) {
                col[current] = 2;
                current = p[current];
            }
            //out.println(Arrays.toString(col));
            

        }
        int ans = 0;
        for (int i = 1 ; i <= n ; i++) {
            if (p[i] != q[i]) {
                ans ++;
            }
        }
        out.println(ans);
        for (int i = 1; i <= n ; i++)
            out.print(q[i] + " ");
        out.println();
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