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



	public final static int INF = (int)2e9;

	String invert(String sign) {
		if (sign.equals(">=")) {
			sign = "<";
		}
		else if (sign.equals(">")) {
			sign = "<=";
		} else if (sign.equals("<=")) {
			sign = ">";
		} else if (sign.equals("<")) {
			sign = ">=";
		}

		return sign;
	}
	static class Pair {
		int l, r;
	}

	public Pair updateBounds(Integer l, Integer r, String sign, char c, int x) {
		if (c == 'N') {
			sign = invert(sign);
		}
		
		if (sign.equals("<=")) {
			r = Math.min(r, x);
		} else if (sign.equals("<")) {
			r = Math.min(r, x-1);
		} else if (sign.equals(">=")) {
			l = Math.max(l, x);
		} else if (sign.equals(">")) {
			l = Math.max(l, x + 1);
		}
		Pair p = new Pair();
		p.l = l;
		p.r = r;
		return p;
	}

	public void solve() throws Exception {
		Integer l = -INF, r = INF;
		int n = nextInt();
		for (int i = 0 ; i < n ; i++) {
			String sign = next();
			int x = nextInt();
			char c = next().charAt(0);
			Pair res = updateBounds(l, r, sign, c, x);
			l = res.l; r = res.r;
			//out.println("l,r = " + l + ", " + r);
		}
		if (l > r) {
			out.println("Impossible");
		} else {
			out.println(l);
		}

	}
}








