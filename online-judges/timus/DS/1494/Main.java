import java.io.*;
import java.util.*;

public class Main {

    int n, arr[];
    TreeSet<Integer> set, antiset;
    
    public void solve() throws IOException {
        n = nextInt();
        arr = new int [n + 1];
        set = new TreeSet<Integer>();
        antiset = new TreeSet<Integer>();
        for (int i = 1 ; i <= n ; i ++) {
            arr[i] = nextInt();
            antiset.add(i);
        }
        for (int i = 1 ; i <= n ; i ++) {
            int x = arr[i];
            if (set.size() > 0 && x > set.last()) {
                // ok
                set.add(x);
                antiset.remove(x);
            } else {
                antiset.remove(x);
                if (set.size() > 0) {
                    Integer c = antiset.ceiling(x);
                    if (c == null || c == set.last() + 1) {
                        // ok
                        
                    } else {
                        out.println("Cheater");
                        return;
                    }

                }
                set.add(x);
            }
            
            //out.println("i = " + i );
            //out.println(set.toString());
            //out.println(antiset.toString());
        }
        out.println("Not a proof");
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