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

	public char [] getZeros(int n) {
		char [] result = new char[n+1];
		result[0] = '1'; result[n] = '1';
		for (int i = 1 ; i < n; i++)
			result[i] = '0';
		return result;
	}

	public char [] increment(char [] a) {
		int n = a.length;
		int pos = (n-1)/2;
	

		while (pos >= 0 && a[pos] == '9') {
			pos --;
		}

		if (pos < 0) {
			return getZeros(n);
		} 
		//out.println("pos = " + pos);
		char [] result = new char[n];
		for (int i = 0 ; i < n; i++) {
			result[i] = a[i];
		}
		result[pos] = (char)(a[pos] + 1);
		for (int i = pos+1 ; i <= (n-1)/2; i++) {
			result[i] = '0';
		}
		for (int i = (n+1)/2 ; i < n ; i++) 
			result[i] = result[n-i-1];
		return result;
	}


	void solveT() throws Exception {
		String s = next();
		char [] a = s.toCharArray();
		int n = a.length;
		int si = -1;
		for (int i = (n-1)/2 ; i >= 0 ; i--) {
			int j = n - i - 1;
			if (a[i] == a[j])
				continue;
			//i < j
			if (a[i] < a[j]) {
				si = j;
			} else {
				si = i;
			}
			break;
		}
		char [] res = null;
		//out.println("si = " + si);
		if (si == -1) {
			res = increment(a);
		} else if (si <= (n-1)/2) {
			// left side is bigger
			for (int i = n - si - 1; i < n ; i++)
				a[i] = a[n-i-1];
			res = a;
		} else {
			res = increment(a);
		}
		for (int i = 0 ; i < res.length; i++)
			out.print(res[i]);
		out.println();
	}


	public void solve() throws Exception {
		int T = nextInt();
		for (int i = 0 ; i < T ; i++) {
			solveT();
		}
	}
}