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

	static class Edge {
		int u, v, d;
	}
	public final static int INF = 1 << 29;

	int [][] runFloyd(int n, ArrayList<Edge> graph) {
		int [][] d = new int[n][n];
		for (int i = 0 ; i < n ; i++) {
			Arrays.fill(d[i], INF);
			d[i][i] = 0;
		}

		for (Edge e : graph) {
			d[e.u][e.v] = e.d;
			d[e.v][e.u] = e.d;
		}
		/*
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < n ; j ++) {
				out.print(d[i][j] + " ");
			}
			out.println();
		}
		*/
		for (int k = 0 ; k < n ; k++) {
			for (int i = 0; i < n ; i++) {
				for (int j = 0 ; j < n ; j++) {
				
					if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) {
						d[i][j] = d[i][k] + d[k][j];
						//out.println("updating " + i + "," + j + " with " + d[i][j] + " through " + k);
					}
				}
			}
		}
		return d;
	}

	int n, m;
	ArrayList<Edge> graph;




	public void solve() throws Exception {
		n = nextInt(); m = nextInt();
		graph = new ArrayList<Edge>();
		for (int i = 0 ; i < m ; i++) {
			Edge e = new Edge();
			e.u = nextInt()-1;
			e.v = nextInt()-1;
			e.d = nextInt();
			graph.add(e);
		}
		int [][] d = runFloyd(n, graph);
		/*
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < n ; j ++) {
				out.print(d[i][j] + " ");
			}
			out.println();
		}
		*/
		int [][] nextCount = new int[n][n];

		for (int x = 0 ; x < n ; x ++) {
			for (Edge e : graph) {
				if (d[x][e.u] < INF && d[x][e.v] < INF && d[x][e.u] == d[x][e.v] + e.d) {
					// that means v is next node on shortest path from x to u
					nextCount[e.u][x] ++;
				}
				if (d[x][e.u] < INF && d[x][e.v] < INF && d[x][e.v] == d[x][e.u] + e.d) {
					// that means v is next node on shortest path from x to u
					nextCount[e.v][x] ++;
				}
			}
		}

		int ans[][] = new int [n][n];

		for (int s = 0 ; s < n ; s ++) {
			for (int t = s + 1 ; t < n ; t ++) {
				if (d[s][t] >= INF)
					continue;
				for (int v = 0 ; v < n ; v ++) {
					if (d[s][v] >= INF || d[v][t] >= INF)
						continue;
					// if v is on shortest path between s and t, 
					// increment ans[s][t] by nextCount[v][s] + nextCount[v][t]
					if (d[s][v] + d[v][t] == d[s][t]) {

						ans[s][t] += nextCount[v][s] + nextCount[v][t];
						
					}
				}
			}
		}
		for (int s = 0 ; s < n ; s ++) {
			for (int t = s + 1 ; t < n ; t ++) {
				out.print( (ans[s][t]/2) + " " );
			}
		}
		out.println();
	}
}





