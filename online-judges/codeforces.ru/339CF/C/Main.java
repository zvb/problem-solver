import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;

/*2A*/

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




	
	int n;
	
	int [] c;
	int [] d;
	int [] x;

	final static int N = 1000*1000 + 100;
	static class Spot implements Comparable<Spot> {
		int a, b;
		Spot(int _a, int _b) {
			a = _a; b = _b;
		}
		public int compareTo(Spot o) {
			return a - o.a;
		}
	}
	Spot [] s;

	public void solve() throws Exception {

		n = nextInt();
		s = new int [n + 1];
		c = new int [N];
		d = new int [N];
		x = new int [N];
		
		out.println(n);
		for (int i = 1 ; i <= n ; i++) {
			int a = nextInt(), b = nextInt();
			s[i] = new Spot(a, b);
		}

		Arrays.sort(s, 1, n+1);
		for (int i = 1 ; i <= n ; i++) {
			x[s[i].a] = i;
		}
		

		int current = -1;
		for (int i = 0 ; i < N ; i++) {
			c[i] = current;
			if (x[i] > 0) {
				current = i;
			}
		}
		d[1] = 0;
		for (int i = 2 ; i <= n ; i++) {
			int pos = s[i].a - s[i].b; // up to this position is destroyed
			int nextIdx = x[pos];
			d[i] = d[nextIdx] + 1;
		}
		int ans = 0;
		int idx = 0;
		for (int i = 1 ; i <= n ; i ++) {
			if (ans < d[i] + n - i) {
				ans = d[i] + n - i;
				idx = i;// we need to destroy up [idx+1, oo]
			}
		}
		int coord = s[idx].a + 1;
		int aa = s[n].a + 1;
		int bb = aa - coord;
		out.println(n - ans);
		
	}
}