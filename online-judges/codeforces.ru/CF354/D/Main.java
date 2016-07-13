import java.io.*;
import java.util.*;

public class Main {

    final int di[] = new int[] {-1, 0,  1, 0};
    final int dj[] = new int[] { 0, -1, 0, 1};

    final char vq[] = new char[] {'+','-','|','^','>','<','v','L','R','U','D','*'};
    final char rq[] = new char[] {'+','|','-','>','v','^','<','U','D','R','L','*'};
    final char next[] = new char[256];


    static class State {
        int i, j, k;
        State(int _i, int _j, int _k) {
            i = _i;
            j = _j;
            k = _k;
        }
    }

    char [][] move = new char[4][];

    boolean canMove(char from, int x) {
        // 0, 1, 2, 3
        for (int i = 0 ; i < move[x].length; i++)
            if (move[x][i] == from)
                return true;
        return false;
    }

    int opposite(int x) {
        // 0 - 2
        // 1 - 3
        return x ^ 2;
    }


    public void solve() throws IOException {

        for (int i = 0 ; i < vq.length; i++) {
            next[vq[i]] = rq[i];
        }

        // up
        move[0] = new char[] {'+', '|', '^', 'L', 'R', 'D'};
        // left
        move[1] = new char[] {'+', '-', '<','R','U','D'};
        // down
        move[2] = new char[] {'+', '|', 'v','L','R','U'};
        // right
        move[3] = new char[] {'+', '-', '>','L','U','D'};
        


        int n = nextInt(), m = nextInt();
        char [][] a = new char[n][m];
        int [][][] d = new int [n][m][4];

        for (int i = 0 ; i < n ; i++) {
            String s = next();
            for (int j = 0 ; j < s.length() ; j++) {
                a[i][j] = s.charAt(j);
                Arrays.fill(d[i][j], 1 << 30);
            }
            
        }

        boolean visited[][][] = new boolean[n][m][4];

        int si = nextInt()-1, sj = nextInt()-1;
        int fi = nextInt()-1, fj = nextInt()-1;

        Queue< State > q = new LinkedList< State > ();
        q.add(new State(si, sj, 0));
        visited[si][sj][0] = true;
        d[si][sj][0] = 0;

        while (!q.isEmpty()) {
            State current = q.poll();
            int i = current.i, j = current.j, k = current.k;
            char currentBlock = a[i][j];
            for (int t = 0 ; t < k ; t ++)
                currentBlock = next[currentBlock];


            if (!visited[i][j][(k+1)%4]) {
                visited[i][j][(k+1)%4] = true;
                d[i][j][(k+1)%4] = d[i][j][k] + 1;
                q.add(new State(i, j, (k+1)%4));
            }

            for (int x = 0 ; x < 4 ; x ++) {
                


                if (!canMove(currentBlock, x) )
                    continue;

                int ni = i + di[x];
                int nj = j + dj[x];

                if ( 0 <= ni  && ni < n && 0 <= nj && nj < m && !visited[ni][nj][k] ) {
                    char nextBlock = a[ni][nj];

                    for (int t = 0 ; t < k ; t ++)
                        nextBlock = next[nextBlock];

                    if (canMove(nextBlock, opposite(x)) ) {
                        visited[ni][nj][k] = true;
                        q.add(new State(ni, nj, k));   
                        d[ni][nj][k] = d[i][j][k] + 1; 
                    }
                    

                }
            }


        }

        int best = 1 << 30;
        for (int i = 0 ; i < 4 ; i++) {
            if (d[fi][fj][i] < best) {
                best = d[fi][fj][i];
            }
        }
        out.println(best < (1 << 30) ? best : -1);
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
