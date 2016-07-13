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
	int m;
	int p;
	String s, op;
	int tin[], tout[], t[] ;
	ArrayList<Integer> g[];

	int nxt[], prv[];

	public void solve() throws Exception {
		n = nextInt() + 2;
		m = nextInt();
		p = nextInt();
		s = next(); s = "(" + s + ")";
		op = next();
		tin = new int [n/2]; // root node
		tout = new int [n/2]; // root node
		t = new int[n];
		nxt = new int[n];
		prv = new int[n];
		for (int i = 0 ; i < n ; i ++) {
			nxt[i] = i+1;
			prv[i] = i-1;
		}

		g = new ArrayList [n/2];

		for (int i = 0 ; i < n/2 ; i++)
			g[i] = new ArrayList<Integer>();

		Stack<Integer> stack = new Stack<>();

		int curIdx = 0;
		

		for (int i = 0 ; i < n; i++) {
			
			if (s.charAt(i) == '(') {
				tin[curIdx] = i;
				t[i] = curIdx;

				if (stack.empty()) {
					stack.push(curIdx);
				} else {
					int parent = stack.peek();
					g[parent].add(curIdx);
					stack.push(curIdx);
				}

				curIdx ++;
			} else {
				int idx = stack.pop();
				tout[idx] = i;
				t[i] = idx;
			}
		}
/*
		for (int i = 0 ; i < n/2 ; i ++) {
			out.print(i + ": ");
			for (int j : g[i]) {
				out.print(j + " ");
			}
			out.println();
		}
		for (int i = 0 ; i < n/2; i ++)
			out.print(tin[i] + " ");
		out.println();		

		for (int i = 0 ; i < n/2; i ++)
			out.print(tout[i] + " ");

		out.println();
*/
		// process ops
		int curPos = p;
		int curNode = t[curPos];

		for (int i = 0 ; i < op.length(); i++) {
			char c = op.charAt(i);
			if (c == 'L') {
				int move = prv[curPos];
				curPos = move;
			} else if (c == 'R') {
				int move = nxt[curPos];
				curPos = move;
			} else {
				curNode = t[curPos];
				int timeIn = tin[curNode];
				int timeOut = tout[curNode];
				//System.err.println("erasing node between " + timeIn + " and " + timeOut);

				
				int leftRef = prv[timeIn];
				int rightRef = nxt[timeOut];
				if (leftRef >= 0)
					nxt[leftRef] = rightRef;
				if (rightRef < n)
					prv[rightRef] = leftRef;

				curPos = rightRef;
				if (curPos >= n - 1) {
					curPos = leftRef;
				}
				//out.println("new curPos = " + curPos);



			}
			//System.err.println("cur pos = " + curPos);
		}
		int cur = 0;
		StringBuilder sb = new StringBuilder();
		while (cur < n) {
			sb.append(s.charAt(cur));
			cur = nxt[cur];
		}
		String result = sb.toString();
		//out.println("result: >"+result+"<");

		out.println(result.substring(1, result.length()-1));
	
	}
}


















