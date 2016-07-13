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

	class Table implements Comparable<Table> {
		int idx, cap, assignedGroup = -1;
		Table(int _idx, int _cap) {
			idx = _idx; cap = _cap;
		}
		public int compareTo(Table o) {
			if (cap < o.cap) return -1;
			if (cap > o.cap) return 1;
			return idx - o.idx;
		}
	}

	class Group implements Comparable<Group> {
		int idx, cap, money;
		Group(int _idx, int _cap, int _money) {
			idx = _idx; cap = _cap; money = _money;
		}
		public int compareTo(Group o) {
			if (money > o.money) return -1;
			if (money < o.money) return 1;
			if (cap < o.cap) return -1;
			if (cap > o.cap) return 1;
			return idx - o.idx;
		}
	}

	int n, k;
	ArrayList<Group> groups ;
	ArrayList<Table> tables;

	public void solve() throws Exception {
		n = nextInt();
		groups = new ArrayList<Group>();
		for (int i = 0 ; i < n ; i++) {
			int cap = nextInt(), price = nextInt();
			groups.add (new Group(i+1, cap, price));
		}
		k = nextInt();
		tables = new ArrayList<Table>();
		for (int i = 0 ; i < k; i++) {
			tables.add(new Table(i+1, nextInt()));
		}

		Collections.sort(groups);
		Collections.sort(tables);
		int totGroups = 0, totRev = 0;
		for (int i = 0 ; i < groups.size() ; i++) {
			// Let's find a table for that group
			Group g = groups.get(i);
			for (int j = 0 ; j < tables.size() ; j++) {
				Table t = tables.get(j);
				if (t.assignedGroup > -1)
					continue;
				if (t.cap >= g.cap) {
					t.assignedGroup = g.idx;
					totGroups ++;
					totRev += g.money;
					break;
				}
			}
		}
		out.println(totGroups + " " + totRev);
		for (int i = 0 ; i < tables.size() ; i++) {
			Table t = tables.get(i);
			if (t.assignedGroup > -1) {
				out.println(t.assignedGroup + " " + t.idx);
			}
		}


	}
}




