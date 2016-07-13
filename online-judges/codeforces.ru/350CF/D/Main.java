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


	int n, k;
	int a[], b[];

	boolean f(int c) {
		long req = 0;

		for (int i = 0 ; i < n ; i++) {
			long reqIng = 1L*a[i]*c;
			if (b[i] < reqIng) {
				req += reqIng - b[i];
			} 
			if (k < req)
				return false;
		}


		return true;
	}
	public void solve() throws Exception {
		n = nextInt();
		k = nextInt();
		a = new int[n];
		b = new int[n];

		for (int i = 0 ; i < n ; i++)
			a[i] = nextInt();
		for (int i = 0 ; i < n ; i++) 
			b[i] = nextInt();

		int lo = 0, hi = (int)2e9;
		while (hi > lo) {
			int mid = lo + (hi - lo + 1)/2;
			if (f(mid))
				lo = mid;
			else
				hi = mid - 1;
			//out.println("lo = " + lo);
		}

		out.println(lo);
	}
}