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

	int n;
	int [] langIdx;
	int [] a;
	int [] b;
	int k;

	public void solve() throws Exception {
		HashMap<Integer, Integer> count = new HashMap<>();
		n = nextInt();
		langIdx = new int[n];

		for (int i = 0 ; i < n ; i++) {
			langIdx[i] = nextInt();
			if (!count.containsKey(langIdx[i]))
				count.put(langIdx[i], 0);

			count.put(langIdx[i], count.get(langIdx[i]) + 1);
		}

		int ans = -1;
		k = nextInt();
		a = new int[k];
		b = new int[k];
		for (int i = 0 ; i < k ; i ++) {
			a[i] = nextInt();
		}
		for (int i = 0 ; i < k ; i ++) {
			b[i] = nextInt();
		}
		int ansGood = -1, ansOk = -1;
		for (int i = 0 ; i < k ; i++) {
			int good = count.containsKey(a[i]) ? count.get(a[i]) : 0;
			int ok = count.containsKey(b[i]) ? count.get(b[i]) : 0;
			//out.println("d " + good + " " + ok);

			if (ans == -1) {
				ans = i;
				ansGood = good;
				ansOk = ok;
			}

			
			if (good > ansGood || (good == ansGood && ok > ansOk)) {
				ans = i;
				ansGood = good;
				ansOk = ok;
			} 
		}
		out.println(ans+1);
	}
}




















