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


	static class Node implements Comparable<Node> {
		int val;
		int idx;
		Node(int _val, int _idx) {
			val = _val;
			idx = _idx;
		}
		public int compareTo(Node o) {
			if (val != o.val)
				return val - o.val;
			return idx - o.idx;
		}
	}

	public final static int INF = 1 << 30;
	int n, a[];
	public void solve() throws Exception {
		n = nextInt();
		a = new int[n];
		TreeSet<Node> t = new TreeSet<Node>();
		for (int i = 0 ; i < n ; i++) {
			a[i] = nextInt();
			if (i > 0) {
				Node left = t.floor(new Node(a[i], INF));
				Node right = t.ceiling(new Node(a[i], -INF));
				int parent = -1;
				if (left == null) {
					parent = right.idx;
				} else if (right == null) {
					parent = left.idx;
				} else {
					parent = Math.max(left.idx, right.idx);
				}
				out.print(a[parent] + " ");
			}

			t.add(new Node(a[i], i));
		}
		out.println();
	}
}


