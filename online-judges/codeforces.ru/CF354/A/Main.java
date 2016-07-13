import java.io.*;
import java.util.*;

public class Main {


    public void solve() throws IOException {
        int n = nextInt();
        int [] a = new int[n];

        int posMin = 0, posMax = 0;
        for (int i = 0 ; i < n ; i++) {
            a[i] = nextInt();
            if (a[i] > a[posMax])
                posMax = i;

            if (a[i] < a[posMin])
                posMin = i;


        }
        int res = Math.abs(posMax - posMin);
        int posSwap[] = new int[] {0, n-1};
        for (int i = 0 ; i < posSwap.length; i++) {
            int toPut = posSwap[i];
            if (toPut != posMin)
                res = Math.max(res, Math.abs(toPut - posMin));
            if (toPut != posMax)
                res = Math.max(res, Math.abs(toPut - posMax));
        }
        out.println(res);


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
