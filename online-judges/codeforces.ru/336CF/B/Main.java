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
	int n;
	
	int [] c;
	int [][] memo;
	boolean [][] calced;

	int rec(int i, int j) {
		if (i == j) 
			return 0;
		if (i > j)
			return 0;
		if (calced[i][j])
			return memo[i][j];

		calced[i][j] = true;
		if (c[i] == c[j]) {
			memo[i][j] = Math.min(memo[i][j], rec(i+1,j-1));
		} 
		for (int k = i ; k < j; k++) {
			memo[i][j] = Math.min(memo[i][j], rec(i,k) + rec(k+1,j) + 1);
		}
		return memo[i][j];
	}

	public void solve() throws Exception {

		n = nextInt();
		c = new int [n+1];
		memo = new int [n+1][n+1];
		calced = new boolean[n+1][n+1];

		for (int i = 1 ; i <= n ; i ++) 
			c[i] = nextInt();

		for (int i = 1 ; i <= n ; i ++) {
			for (int j = 1 ; j <= n; j++) {
				memo[i][j] = 1 << 30;
			}
		}
		out.println(rec(1, n)+1);
		/*for (int i = 1 ; i <= n ; i ++) {
			for (int j = 1 ; j <= n; j++) {
				out.print((memo[i][j] < (1 << 30) ? memo[i][j] : 9) + " ");
			}
			out.println();
		}*/

		
	}
}