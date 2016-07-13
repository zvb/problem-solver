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

	// Assuming a[fromIdx...toIdx-1] is sorted,
	// finds the largest index of the element that is <= val.
	// Returns toIdx if all elements are > val
	int lowerBound(int [] a, int fromIdx, int toIdx, int val) {
		if (toIdx == fromIdx)
			return toIdx;
		int lo = fromIdx, hi = toIdx;
		while (hi > lo) {
			int mid = lo + (hi - lo + 1)/2;
			if (a[mid] <= val) 
				lo = mid ;
			else
				hi = mid - 1;
		}
		return lo;
	}

	// Assuming a[fromIdx...toIdx-1] is sorted,
	// finds the smallest index of the element that is > val.
	// Returns toIdx if all elements are > val
	int upperBound(int [] a, int fromIdx, int toIdx, int val) {
		if (toIdx == fromIdx)
			return toIdx;
		int lo = fromIdx, hi = toIdx;
		while (hi > lo) {
			int mid = lo + (hi - lo)/2;
			if (a[mid] > val) 
				hi = mid;
			else
				lo = mid + 1;
		}
		return lo;
	}

	int n;
	long k;
	int [] c;
	long [] sum;




	// How many days will it take to lift all people to the level >= level?
	long reqUp(int level) {
		int idx = lowerBound(c, 0, n+1, level - 1);
		//out.println("In reqUp, idx = " + idx);
		long s = sum[idx];
		return 1L * level * idx - s;
	}

	// How many days will it take to down all people to the level <= level?
	long reqDown(int level) {
		int idx = upperBound(c, 0, n+1, level);
		//out.println("In reqDown, idx = " + idx);
		long s = sum[n] - sum[idx-1];
		return s - 1L * level * (n - idx + 1);
	}

	// min level if we up people in days
	int up(long days) {
		int lo = c[1], hi = c[n];
		while (hi > lo) {
			int mid = lo + (hi - lo + 1)/2;
			long req = reqUp(mid);
			//out.println("In up, mid = " + mid + " req = " + req);
			if (req > days)
				hi = mid - 1;
			else
				lo = mid;
		}
		return lo;
	}
	int down(long days) {
		int lo = c[1], hi = c[n];
		while (hi > lo) {
			int mid = lo + (hi - lo)/2;
			long req = reqDown(mid);
			//out.println("In down, mid = " + mid + " req = " + req);
			if (req <= days)
				hi = mid;
			else
				lo = mid + 1;
		}
		return lo;
	}

	public void solve() throws Exception {
		n = nextInt(); k = nextLong();

		c = new int [n+1];
		sum = new long [n+1];


		for (int i = 1 ; i <= n ; i ++) {
			c[i] = nextInt();
		}
		Arrays.sort(c, 1, n + 1);
		for (int i = 1 ; i <= n ; i ++) {
			sum[i] = sum[i-1] + c[i];
		}

		if (k == 0) {
			out.println(c[n] - c[1]);
			return;
		}


		int minLevel = up(k), maxLevel = down(k);
		//out.println("minLevel " + minLevel + " maxLevel " + maxLevel);
		if (minLevel >= maxLevel) {
			out.println( sum[n] % n == 0 ? 0 : 1 );
		} else {
			out.println(maxLevel - minLevel);
		} 
	}
}