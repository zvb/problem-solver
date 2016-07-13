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


	int a[], n, k, b[];


	public void solve() throws Exception {
		n = nextInt(); k = nextInt();
		a = new int [n+1];
		b = new int [n+1];
		for (int i = 1 ; i <= n ; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a, 1, n + 1);
		int pos = 1;

		for (int i = 1 ; i <= k ; i++) {
			int j = i;
			while ( j <= n ) {
				b[j] = a[pos ++];
				j += k;
			}
		}
		out.println(Arrays.toString(b));
		long res = 0;
		for (int i = 1 ; i <= n - k ; i ++) {
			res += Math.abs(b[i] - b[i+k]);
			out.println("res = " + res);
		}
		out.println(res);
	}
}