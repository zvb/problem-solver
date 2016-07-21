import java.io.*;
import java.util.*;

public class Main {


    public void solve() throws IOException {
        int n = nextInt(), h = nextInt(), k = nextInt();
        int a[] = new int[n];

        for (int i = 0 ; i < n ; i++) {
            a[i] = nextInt();
        }

        long t = 0;
        long current = 0;
        for (int i = 0 ; i < n ; i++) {
            if (current + a[i] <= h) {
                current += a[i];
                continue;
            }

            //out.println("i = " + i + " current = " + current);
            long d = current + a[i] - h;
            long waitTime = (d + k - 1) / k;
            //out.println("wait time = " + waitTime);
            t += waitTime;
            current = Math.max(0, 0L + current - waitTime * k);
            current += a[i];


            
        }
        t += (current + k - 1) / k;
        out.println(t);
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