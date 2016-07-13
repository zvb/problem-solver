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

	

	int n, a[], lastNonNull[];


	public final static int INF = Integer.MAX_VALUE/2;

	public void solve() throws Exception {
		int n = nextInt();
		a = new int [n];
		lastNonNull = new int[n];

		int lastNonNullIdx = -1;
		for (int i= 0 ; i < n ; i++) {
			a[i] = nextInt();
			lastNonNull[i] = lastNonNullIdx;
			if (a[i] > -1) {
				lastNonNullIdx = i;
			} 
			
		}
		int startIdx = 0;
		int l = -INF, r = INF;
		int ans = 1;
		for (int i = 0 ; i < n ; i++) {
			out.println("" + diff + "\t" + startIdx + "\t" + ans);
			if (a[i] == -1) {
				// verify that the current seq works. If not, start a new one
				if (l == -INF && r == INF) {
					// go ahead
					continue;
				}

				if (l > -INF) {
					long projL = 1L * (i - startIdx) * l;
				}

			} else {
				if (diff == ANY) {
					startIdx = i;
				} else {
					
					long proj = 0L + a[startIdx] + 1L*(i - startIdx) * diff;
					if (proj != a[i]) {
						ans ++;
						startIdx = i;
						diff = ANY;
					} else {
						// OK 
					}

				}
				
			}
		}

		out.println(ans);


		

		



	}
}








