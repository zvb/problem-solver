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

	public final static int N = 6200;
	int dp[][];

	String s;

	void runT() throws Exception {
		s = next();
		int n = s.length();
		
		
		//dp[len][startIdx]
		Arrays.fill(dp[0], 0, n, 0);
		Arrays.fill(dp[1], 0, n, 0);
		
		

		for (int len = 2 ; len <= n ; len ++) {
			for (int i = 0; i + len - 1 < n ; i++) {
				
				dp[2][i] = dp[1][i+1] + 1;
				if (dp[2][i] > dp[1][i] + 1)
					dp[2][i] = dp[1][i] + 1;
				
				if (s.charAt(i) == s.charAt(i + len - 1)) {
					if (dp[2][i] > dp[0][i+1])
						dp[2][i] = dp[0][i+1];
				}

			}
			// TODO: copy
			System.arraycopy(dp[1], 0, dp[0], 0, n);
			System.arraycopy(dp[2], 0, dp[1], 0, n);
		}
		out.println(dp[2][0]);

	}



	public void solve() throws Exception {
		dp = new int[3][N];
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			runT();
		}
	}
}