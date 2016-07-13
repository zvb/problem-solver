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
	int [] d;
	Spot [] s;

	public void solve() throws Exception {

		n = nextInt();
		s = new Spot [n + 1];
		d = new int [n + 1];
		

		for (int i = 1 ; i <= n ; i++) {
			int a = nextInt(), b = nextInt();
			s[i] = new Spot(a, b);
		}

		Arrays.sort(s, 1, n+1);
		TreeMap<Spot, Integer> tree = new TreeMap<Spot, Integer>();
		for (int i = 1 ; i <= n ; i ++) {
			tree.put(s[i], i);
		}

		for (int i = 1 ; i <= n ; i++) {
			int x = s[i].a - s[i].b; // position up to which everything is dstyd
			Spot search = new Spot(x - 1, 0);
			Spot next = tree.floorKey(search);
			if (next != null) {
				Integer idx = tree.get(next);
				d[i] = d[idx] + 1;
			} else {
				d[i] = 1;// only ith is saved
			}
		}

		int ans = 1;
		for (int i = 1 ; i <= n ; i++) {
			ans = Math.max(d[i], ans);
		}
		
		out.println(n - ans);
		
	}
}