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



	int x[], y[];

	public void solve() throws Exception {
		int sign = 1;
		int a = 0, b = 0;
		int n = -1;

		String line = in.readLine();
		for (int i = 0 ; i < line.length() ; i++) {
			char c = line.charAt(i);
			if (c == '?') {
				if (sign > 0)
					a ++;
				else
					b++;
			} else if (c == '-') {
				sign = -1;
			} else if (c == '+') {
				sign = 1;
			} else if (c == '=') {
				n = Integer.parseInt(line.substring(i + 2));
				break;
			}
		}
		//out.println(a + " " + b + " " + n);
		boolean a_pos = a == 0, b_pos = b == 0;
		if (a - b*n > n || n > n*a - b || a == 0) {
			out.println("Impossible");
			return;
		}



		x = new int [a]; y = new int [b];
		int pa = 0, pb = 0;
		
		//int nn = n;
		if (b == 0) {
			for (int i = 0 ; i < n ; i ++) {
				x[pa++] ++;
				if (pa == a) {
					pa = 0;
				}
			}
		} else {
			for (int i = 0 ; i < n ; i ++) {
				x[pa++] ++;
				if (pa == a) {
					pa = 0;
					a_pos = true;
				}
			}
			while (!a_pos || !b_pos) {
			
				x[pa++] ++;
				if (pa == a) {
					pa = 0;
					a_pos = true;
				}

				y[pb++] ++;
				if (pb == b) {
					pb = 0;
					b_pos = true;
				}
			}

			
		}
		
		
		out.println("Possible");
		sign = 2;
		pa = 0; pb = 0;
		for (int i = 0 ; i < line.length(); i++) {
			char c = line.charAt(i);
			if (c == '+') {
				sign = 1;
			} else if (c == '-') {
				sign = -1;
			} else if (c == '?') {
				if (sign > 0) {
					if (sign == 1)
						out.print("+ ");
					out.print(x[pa++] + " ");
				} else {
					out.print("- " + y[pb++] + " ");
				}
			} else if (c == '=') {
				out.println("= " + n);
				break;
			} 
		}

	}
}