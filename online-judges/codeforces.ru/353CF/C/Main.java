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

	


	int n, a[], p[];


	
	public void solve() throws Exception {
		n = nextInt();
		a = new int [n];
		
		for (int i = 0 ; i < n ; i++) 
			a[i] = nextInt();

		HashMap<Long, Integer> count = new HashMap<Long, Integer>();

		long sum = 0;
		for (int i = 0 ; i < n ; i ++) {
			sum += a[i];

			if (count.containsKey(sum)) {
				count.put(sum, count.get(sum) + 1);
			} else {
				count.put(sum, 1);
			}

			
		}

		Map.Entry<Long, Integer> best = null;
		for (Map.Entry<Long, Integer> e : count.entrySet()) {
			
			if (best == null || e.getValue() > best.getValue()) {
				best = e;
			}
		
			
		}

		out.println(n - best.getValue());

		




		// 2 1 -1 0 0 -1 1 0 -1 -1
		// 2 3  2 2 2  1 2 2  1  0

		// 1 -1 0 0 -1 1 0 -1 -1 2
		// 1 0  0 0 -1 0 0 -1 -2 0



	}
}






