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


	int [] id;
	int n;
	int k;
	public void solve() throws Exception {
		n = nextInt(); k = nextInt();
		id = new int [n+1];
		for (int i = 1 ; i <= n ; i++)
			id[i] = nextInt();

		int row = 1;
		while ( 1L*(row)*(row+1) < 2L*k)
			row ++;

		int col = k - (int)(1L*(row)*(row-1)/2);
		//out.println(row + " " + col);
		if (col == 0) {
			col = row-1;
		}
		out.println(id[col]);
	}
}