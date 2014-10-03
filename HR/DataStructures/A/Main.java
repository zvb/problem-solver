import java.util.*;
import java.io.*;
public class Main {
    public class Vector<T> {
        private T [] a;
        private int size;
        private int capacity;
        public Vector() {
            a = (T [])(new Object[10]);
            size = 0;
            capacity = 10;
        }
        public void push_back(T x) {
            if (size == capacity) {
                capacity *= 2;
                T [] A = (T [])(new Object[capacity]);
                for (int i = 0 ; i < size ; i ++)
                    A[i] = a[i];
                A[size ++] = x;
                a = A;
            } else {
                a[size ++] = x;
            }
        }
        public void pop_back() {
            if (size == 0) return;
            size --;
            if (capacity > 10 && 2*size <= capacity) {
                capacity /= 2;
                T [] A = (T [])(new Object [capacity]);
                for (int i = 0 ; i < size ; i ++)
                    A[i] = a[i];
                a = A;
            }
        }
        public T back() {
            if (size == 0)
                return null;
            return a[size - 1];
        }
        public int size() {
            return size;
        }
        public int capacity() {
            return capacity;
        }
        public void clear() {
            capacity = 10;
            size = 0;
            a = (T [])(new Object[capacity]);
        }
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append("[");
            for (int i = 0 ; i < size - 1 ; i ++)
                sb.append(a[i].toString() + ", ");
            if (size >= 1)
                sb.append(a[size - 1].toString());
            sb.append("]");
            return sb.toString();
        }
        public T get(int index) {
            if (index < 0 || index >= size)
                throw new ArrayIndexOutOfBoundsException("Vector out of bounds");
            return a[index];
        }
    }
    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    public String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    public void solve() throws IOException {
        Vector<Integer> v = new Vector<Integer>();
        String token = null;
        while ( true ) {
            token = next();
            if (token.equals("push")) {
                int x = Integer.parseInt(next());
                v.push_back(x);
                out.println("ok");
            } else if (token.equals("back")) {
                out.println(v.back());
            } else if (token.equals("size")) {
                out.println(v.size());
            } else if (token.equals("clear")) {
                v.clear();
                out.println("ok");
            } else if (token.equals("pop")) {
                out.println(v.back());                
                v.pop_back();
            } else
                break;
        }
        out.println("bye");
    }
    public Main() throws IOException {
        br = new BufferedReader(new FileReader("input.txt"));
        out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        out.close();
        br.close();
    }
        
    public static void main(String args[]) throws Exception {
        new Main();
    }
}
