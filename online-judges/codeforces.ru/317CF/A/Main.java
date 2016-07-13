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
	

	
	long f(int a, int b, int c, int l) {
		long ans = 0;
		int mx = Math.max(a, Math.max(b, c));
		for (int al = mx - a ; al <= l ; al ++) {
			int u = Math.min(a + al - b - c, l - al);
			if (u < 0)
				continue;
			ans += 1L*(u+1)*(u+2)/2;
		}
		//out.println("ans = " + ans);
		return ans;
	}

	int da[], db[], dc[];
	final int N = 1000*1000;

	int a, b, c, l;
	public void solve() throws Exception {
		a = nextInt(); b = nextInt(); c = nextInt(); l = nextInt();
		long ans = 1L * (l + 3) * (l + 2) * (l + 1) / 6;
		ans -= f(a, b, c, l) + f(b, a, c, l) + f(c, a, b, l);
		out.println(ans);
		

		
	}
}