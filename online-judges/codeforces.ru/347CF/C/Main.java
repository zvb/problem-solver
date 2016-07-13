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



	long a[] = new long[100];
	long p10[] = new long[10];

	public void solve() throws Exception {
		p10[0] = 1L;
		for (int i = 1 ; i < 10 ; i++) {
			p10[i] = p10[i-1] * 10;
		}

		a[1] = 1989L
		for (int i = 2 ; i < 100 ; i ++) {
			a[i] = a[i-1] + p10[i-1];
			if (a[i] > 1000L*1000*1000)
				break;
		}
		int n = nextInt();
		for (int i = 0 ; i < n ; i++) {
			String s = next();
			String X = s.substring(s.indexOf('\'')+1);
			int x = Integer.parseInt(X);

			int num = X.length();
			String cur = String.valueOf(a[num]), next = String.valueOf(a[num+1]);
			if ()

		}
	}
}