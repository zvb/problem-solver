import java.io.*;
import java.util.*;

public class Main {

    
    public void solve() throws IOException {
        int n = nextInt(), m = nextInt();

        long totalOccupied = 0;
        boolean cols[] = new boolean[n];
        boolean rows[] = new boolean[n];
        int colCount = 0;
        int rowCount = 0;
        for (int i=0 ; i < m ; i++) {
            int x = nextInt()-1, y = nextInt()-1;
            if (!cols[y]) {
                totalOccupied += n - (rowCount + (!rows[x] ? 1 : 0));
                
            }

            if (!rows[x]) {
                totalOccupied += n - (colCount + (!cols[y] ? 1 : 0));
                
            }

            if (!rows[x] && !cols[y])
                totalOccupied++;

            if (!rows[x]) {
                rows[x] = true;
                rowCount ++;
            }

            if (!cols[y]) {
                cols[y] = true;
                colCount ++;
            }
            out.print((1L*n*n - totalOccupied) + " ");
        }
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