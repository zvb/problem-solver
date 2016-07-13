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



	int n, c, t;
	int [] x;

	boolean possible(int d) {
		int lastPos = (int)(-1e9) + 100;
		int remaining = c;
		for (int i = 0 ; i < n ; i ++) {
			if (x[i] - lastPos >= d) {
				lastPos = x[i];
				remaining --;
			}
		}
		return remaining <= 0;
	}

	void solveT(int tc) throws Exception {
		n = nextInt();
		c = nextInt();
		x = new int [n];
		for (int i = 0 ; i < n ; i++) {
			x[i] = nextInt();
		}
		Arrays.sort(x);
		int lo = 0, hi = (int)1e9;
		while (hi > lo) {
			int mid = lo + (hi - lo + 1)/2;
			if (possible(mid))
				lo = mid;
			else
				hi = mid - 1;
		}
		out.println(lo);
	}

	public void solve() throws Exception {
		t = nextInt();
		for (int i = 0 ; i < t ; i++) {
			solveT(i);
		}
	}
}