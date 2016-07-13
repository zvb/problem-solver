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





	public void solve() throws Exception {
		int n = nextInt();
		int a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt();
		int p = c - b;
		int q = d - a;
		int l = Math.max(Math.max(1, 1-q), Math.max(1-p, 1-q-p));
		int r = Math.min(Math.min(n-p-q, n-p), Math.min(n-q, n));
		if (l > r) {
			out.println(0);
			return;
		}
		out.println(1L * n * (r - l + 1));
	}
}