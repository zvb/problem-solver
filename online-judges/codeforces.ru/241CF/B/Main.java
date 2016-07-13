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



	int m, n;
	int t[][], f[][];

	public void solve() throws Exception {
		m = nextInt();
		n = nextInt();
		t = new int [m + 1][ n + 1];
		f = new int [n][m];
		for (int i = 0 ; i < m ; i ++) {
			for (int j = 0 ; j < n ; j++) {
				t[i][j] = nextInt();
			}
		}
		for (int j = 0 ; j < n ; j++) {
			for (int i = 0 ; i < m ; i ++) {
				if (j == 0) {
					f[j][i] = t[i][j] + (i > 0 ? f[j][i-1] : 0);
				} else {
					
					f[j][i] = Math.max(f[j-1][i], ( i > 0 ? f[j][i-1] : 0)) + t[i][j];
				}
			}	
		}
		for (int i = 0 ; i < m ; i++) {
			out.print(f[n-1][i] + " ");
		}
		

	}
}






