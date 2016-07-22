import java.io.*;
import java.util.*;

public class Main {

    
    public void solve() throws IOException {
        int n = nextInt();
        int a[] = new int[n];
        int sum = 0;
        for (int i = 0 ; i < n ; i++) {
            a[i] = nextInt();
            sum += a[i];
        }

        sum = sum * 2 / n;
        for (int i = 0 ; i < n ; i++) {
            if (a[i] == -1) {
                continue;
            }
            for (int j = i + 1 ; j < n ; j ++) {
                if (a[j] == -1)
                    continue;

                if (a[i] + a[j] == sum) {
                    out.println((i+1) + " " + (j+1));
                    a[i] = -1;
                    a[j] = -1;
                    break;
                }
            }
        }



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