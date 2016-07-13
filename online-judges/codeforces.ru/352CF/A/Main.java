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


	static class Pair implements Comparable<Pair> {
		double dist;
		int i;
		public int compareTo(Pair o) {
			if (dist < o.dist) return -1;
			if (dist > o.dist) return 1;
			return i - o.i;
		}
	}
	double ax, ay, bx, by, tx, ty;
	double [] d;
	double [] a, b;
	int n;

	ArrayList<Pair> pa;
	ArrayList<Pair> pb;

	public void solve() throws Exception {
		ax = nextDouble();
		ay = nextDouble();
		bx = nextDouble();
		by = nextDouble();
		tx = nextDouble();
		ty = nextDouble();
		n = nextInt();
		d = new double [n];
		a = new double [n];
		b = new double [n];
		pa = new ArrayList<Pair>();
		pb = new ArrayList<Pair>();
		double D = 0.0;
		for (int i = 0 ; i < n ; i++) {
			double x = nextDouble(), y = nextDouble();
			d[i] = Math.sqrt( (x-tx)*(x-tx) + (y-ty)*(y-ty));
			D += d[i];
			a[i] = Math.sqrt( (x-ax)*(x-ax) + (y-ay)*(y-ay));
			b[i] = Math.sqrt( (x-bx)*(x-bx) + (y-by)*(y-by));
		}

		double ans = 1e100;
		for (int i = 0 ; i < n ; i++) {
			ans = Math.min(ans, 2*D - d[i] + a[i]);
			Pair pair = new Pair();
			pair.dist = a[i] - d[i];
			pair.i = i;
			pa.add(pair);
		}

		for (int i = 0 ; i < n ; i++) {
			ans = Math.min(ans, 2*D - d[i] + b[i]);
			Pair pair = new Pair();
			pair.dist = b[i] - d[i];
			pair.i = i;
			pb.add(pair);
		}
		Collections.sort(pa);
		Collections.sort(pb);
		if (n > 1) {
			for (int i = 0 ; i < 2; i++) {
				for (int j = 0 ; j < 2 ; j++) {
					if (pa.get(i).i != pb.get(j).i)
						ans = Math.min(ans, 2*D + pa.get(i).dist + pb.get(j).dist);
				}
			}
		} 
		out.println(ans);


	}
}