import java.io.*;
import java.util.*;

public class Main {
    BufferedReader bf;
    StringTokenizer st;
    PrintWriter out;
    int n, m, x;
    Event [] e;
    int l[], r[];
    TreeSet<Event> set;
    
    public void solve() throws IOException {
        n = nextInt();
        e = new Event [2*n];
        l = new int[n];
        r = new int[n];
        for (int i = 0 ; i < n ; i++) {
            l[i] = nextInt(); r[i] = nextInt();
            e[2*i] = new Event(l[i], i, 0);
            e[2*i+1] = new Event(r[i], i, 1);
        }
        set = new TreeSet<Event>();
        Arrays.sort(e);
        m = nextInt();
        int p = -1;
        /*
         for (Event event : e)
         out.print(event.x + " " + event.id + ",  ");
         out.println();
         */
        for (int i = 0 ; i < m ; i++) {
            x = nextInt();
            //out.println("x = " + x);
            boolean ok = false;
            while (p + 1 < 2*n && x >= e[p+1].x) {
                p ++;
                if (e[p].isRight == 0) {
                    set.add(e[p]);
                } else {
                    if (e[p].x == x) {
                        ok = true;
                        out.println((e[p].id + 1));
                    }
                    set.remove(new Event(l[e[p].id], e[p].id, 0));
                }
            }
            /*out.println("p = " + p);
             for (Event event: set)
             out.print(event.x + " " + event.id + ",  ");
             out.println();
             */
            if (!ok) {
                //out.print("ans = ");
                if (set.size() > 0) {
                    out.println(set.last().id + 1);
                } else
                    out.println("-1");
            }
            //out.println();
        }
    }
    
    public class Event implements Comparable {
        int x, id, isRight;
        public Event(int _x, int _id, int _isRight) {
            x = _x; id = _id; isRight = _isRight;
        }
        public int compareTo(Object _o) {
            Event o = (Event)_o;
            if (x != o.x) return x - o.x;
            if (isRight + o.isRight == 2)
                return id - o.id;
            if (isRight + o.isRight == 1)
                return o.isRight - isRight;
            return r[o.id] - r[id];
        }
        public int hashCode() {
            final int p = 31;
            int result = 0;
            result = result * p + x;
            result = result * p + id;
            result = result * p + isRight;
            return result;
        }
        public boolean equals(Object o) {
            if (this == o) return true;
            Event _o = (Event)o;
            return this.compareTo(_o) == 0;
        }
    }
    
    
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