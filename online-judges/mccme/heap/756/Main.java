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

	public static class IntMultiSet {
		private TreeMap<Integer, Integer> index;
		private int size = 0;
		public IntMultiSet() {
			index = new TreeMap<>();
		}

		public void add(int x) {
			if (!index.containsKey(x))
				index.put(x, 0);
			index.put(x, index.get(x) + 1);
			size ++;
		}

		public void remove(int x) {
			if (!index.containsKey(x))
				throw new RuntimeException("Key error " + x);

			int count = index.get(x) - 1;
			if (count > 0) 
				index.put(x, count);
			else
				index.remove(x);

			size --;
		}

		public Integer first() {
			return index.firstKey();
		}

		public Integer last() {
			return index.lastKey();
		}
		public int size() {
			return this.size;
		}

		// TODO: floor(), ceiling()
	}


	int n, k;
	int [] a;


	public void solve() throws Exception {
		n = nextInt();
		k = nextInt();
		a = new int [n];
		IntMultiSet set = new IntMultiSet();
		for (int i = 0 ; i < n ; i ++) {
			a[i] = nextInt();
		}
		for (int i = 0 ; i < n ; i ++) {
			if (set.size() == k) 
				out.println(set.first());

			set.add(a[i]);
			if (i >= k)
				set.remove(a[i-k]);
		}
		if (set.size() == k) 
			out.println(set.first());
	}
}