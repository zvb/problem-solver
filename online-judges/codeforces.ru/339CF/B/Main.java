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


	int n;
	int [] a;
	long [] s;
	long m;
	int A;
	int cf, cm;
	Entry [] e ;
	long getSum(int from, int to) {
		if (from > to)
			return 0L;
		return s[to] - s[from-1];
	}
	static class Entry {
		int val, idx, req;
		Entry(int _val, int _idx) {
			val = _val; idx = _idx;
		}
	}


	public void solve() throws Exception {

		n = nextInt();
		A = nextInt();
		cf = nextInt();
		cm = nextInt();
		m = nextLong();
		a = new int [n + 1];
		s = new long [n + 1];
		e = new Entry [n+1];
		for (int i = 1 ; i <= n ; i++) {
			a[i] = nextInt();
			e[i] = new Entry(a[i], i);
		}
		Arrays.sort(a, 1, n+1);
		Comparator<Entry> byVal = new Comparator<Entry>() {
			public int compare(Entry l, Entry r) {
				return l.val - r.val;
			}
		};
		Comparator<Entry> byIdx = new Comparator<Entry>() {
			public int compare(Entry l, Entry r) {
				return l.idx - r.idx;
			}
		};
		Arrays.sort(e, 1, n + 1, byVal);
		for (int i = 1 ; i <= n ; i++) {
			s[i] = s[i-1] + a[i];
		}
		long best = 0;
		int p = n;
		int bb = 0, kk = 0;
		for (int k = 0 ; k <= n ; k++) {
			long mRemaining = m - (1L * A * k - getSum(n-k+1, n));
			if (mRemaining < 0)
				break;
			
			//out.println("k = " + k);
			//out.println("mRemaining = " + mRemaining);
			/*b = a[p];
			while (getSum(1, p) + mRemaining < 1L*A*b) {
				b --;
				while (b < a[p])
					p--;
			}*/

			p = Math.min(n - k, p);
			if (p == 0) {
				if (best < 1L*n*cf + 1L*A*cm) {
					best = 1L*n*cf + 1L*A*cm;
					bb = A;
					kk = n;
				}
				
				break;
			}
			if (a[p] >= A)
				continue;
			while (getSum(1, p) + mRemaining < 1L * a[p] * p) {
				p --;
			}
			//out.println("p = " + p);
			long required = 1L * p * a[p] - getSum(1, p); // <= mRemaining

			long rest = mRemaining - required;
			int b = (int)(rest / p) + a[p];
			if (b > A)
				b = A;
			//out.println("b = " + b);
			if (best < 1L * b * cm + 1l* k * cf) {
				best = 	1L * b * cm + 1l* k * cf;
				bb = b;
				kk = k;
			}
			
		}
		out.println(best);
		for (int i = 1 ; i <= n ; i++) {
			if (e[i].val < bb)
				e[i].val = bb;
			if (i + kk - 1 >= n) {
				e[i].val = A;
			}
		}
		Arrays.sort(e, 1, n + 1, byIdx);
		for (int i = 1 ; i <= n ; i ++) {
			out.print(e[i].val + " ");
		}
	}
}