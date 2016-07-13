import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;


public class Main {
	public static void main(String[] args) throws Exception {
		Main mainClass = new Main();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	public String next() throws Exception {
		if (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(next());
	}



	public double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	public Main() throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));

		solve();
		out.close();
	}

	public class MovingWindow {
		private int a[];
		private int pos = -1;
		MovingWindow(int sz) {
			a = new int [sz];
		}
		int add(int x) {
			pos ++;
			if (pos == a.length)
				pos = 0;
			int save = a[pos];
			a[pos] = x;
			return save;
		}
		int get(int positionsBefore) {
			int position = (pos - positionsBefore + a.length) % a.length;
			return a[position];
		}
	}
	public final static int p = 3;

	public long getHash(String s) {
		long result = 0L;
		
		for (int i = 0 ; i < s.length() ; i ++) {
			result = result * p + (int)s.charAt(i);
		}
		return result;
	}

	

	public void solve() throws Exception {
		while (true) {
			String n = in.readLine();
			if (n == null)
				break;
			String s = in.readLine();
			int sz = s.length();
			int c;
			long hash = 0L;
			final long searched = getHash(s);
			//out.println("Searched = " + searched);
			int count = 0;
			long pn = 1L;
			for (int i = 0 ; i < sz ; i++)
				pn *= p;
			MovingWindow w = new MovingWindow(sz);
			//System.err.println("n = " + n);
			//System.err.println("s = " + s);
			while (true) {
				c = in.read();
				if (c == 10)
					break;
				// Do rolling hashes
				//System.err.println("Read " + c);
				if (c == -1)
					return;
				
				hash = hash * p + c;
				int e = w.add(c);
				//System.err.println("e = " + e);
				if (count >= sz) {
					hash -= e * pn;
				}
				if (count >= sz - 1 && searched == hash) {
					out.println(count - sz + 1);
				}
				//System.err.println("count = " + count + ", " + "hash = " + hash);
				count ++;
			}
		}
	}
}