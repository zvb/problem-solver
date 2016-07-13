import java.io.*;
import java.util.*;

public class Main {
    long X;
    int L;
    String s;
    int [][] m;
    int need[] = {'i', 'j', 'k'};
    public int mult(int a, int b) {
        if (b < 0) {
            a = -a;
            b = -b;
        }
        
    }
    public int get(int h) {
        int r = '1';
        for (int i = 0 ; i < L ; i ++) {
            if (r > 0) {
                r = m[r][s.charAt(i)];
            } else {
                r = -m[-r][s.charAt(i)];
            }
        }
        int res = '1';
        while (h > 0) {
            if (h % 2 == 0)
                res = (r > 0 ? m[res][s.charAt(i)] : -m[-r][]);
            h /= 2;
        }
    }
    public void solveTestCase(int t) throws IOException {
        L = nextInt();
        X = nextLong();
        s = next();
        int cur = '1';
        int p = 0;
        int a = '1';
        int l = -1;
        for (int i = 0 ; i < X; i++) {
            for (int j = 0 ; j < L ; j++) {
                if (cur > 0) {
                    cur = m[cur][s.charAt(j)];
                } else {
                    cur = -m[-cur][s.charAt(j)];
                }
                if (cur == need[p]) {
                    p ++;
                    if (p == 3) {
                        l = i + 1;
                        for (int k = j + 1; k < L ; k ++) {
                            if (a > 0) {
                                a = m[a][s.charAt(k)];
                            } else {
                                a = -m[-a][s.charAt(k)];
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    public void solve() throws IOException {
        m = new int[111][111];
        m['1']['1'] = '1';
        m['1']['i'] = 'i';
        m['1']['j'] = 'j';
        m['1']['k'] = 'k';
        m['i']['i'] = -'1';
        m['i']['j'] = 'k';
        m['i']['k'] = -'j';
        m['j']['j'] = -'1';
        m['j']['k'] = 'i';
        m['k']['k'] = -'1';
        for (int i = 0 ; i < 111 ; i ++) {
            for (int j = 0; j < 111 ; j ++) {
                if (m[i][j] != 0) {
                    m[j][i] = m[i][j];
                    //out.print((char)m[i][j] + " ");
                }

            }
            out.println();
        }
        int T = nextInt();
        for (int i = 1 ; i <= T ; i++) 
            solveTestCase(i);
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