import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class DoubleWeights {

	public final static int INF = 1 << 30;
	int [][] getCost(String [] w) {
		int n = w.length;
		int [][] a = new int[n][n];
		for (int i = 0 ; i < n ; i ++)
			Arrays.fill(a[i], INF);

		for (int i = 0 ; i < n ; i++) {
			String s = w[i];
			for (int j = 0 ; j < n ; j++) {
				char c = s.charAt(j);
				if (c != '.')
					a[i][j] = c - '0';
			}
		}
		return a;
	}

	static class Node implements Comparable<Node> {
		int d, r, idx;

		Node(int _d, int _r, int _idx) {
			d = _d; r = _r; idx = _idx;
		}
		@Override
		public int compareTo(Node o) {
			if (this.d * this.r != o.d * o.r)
				return idx - o.idx;

			return this.d * this.r - o.d * o.r;
		}
	}


	public int minimalCost(String[] weight1, String[] weight2) {
		int [][] a = getCost(weight1);
		int [][] b = getCost(weight2);

		int n = weight1.length;
		int d[] = new int[n];
		Arrays.fill(d, INF);
		d[0] = 0;

		PriorityQueue<Node> queue = new PriorityQueue<Node>();
		queue.add(new Node(0, 0, 0));

		while (!queue.isEmpty()) {
			Node current = queue.poll();
			int idx = current.idx, dist = current.d * current.r;
			if (d[idx] != dist)
				continue;

			for (int i = 0 ; i < n ; i ++) {
				int fe = a[idx][i], be = b[idx][i];
				if (fe >= INF || be >= INF)
					continue;

				int newDist = (current.d + fe) * (current.r + be);
				if (newDist < d[i]) {
					d[i] = newDist;
					queue.add(new Node(current.d + fe, current.r + be, i));
				}
			}


		}


		return d[1] < INF ? d[1] : -1;
	}
}
