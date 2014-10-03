import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class BuildingHeights {
	int [] h, s;
    int n;
    int getSum(int l, int r) {
        if (l == 0)
            return s[r];
        return s[r] - s[l - 1];
    }
    int solve(int m) {
        int best = 1 << 30;
        for (int i = 0 ; i < n ; i ++) {
            if (i + 1 < m) continue;
            best = Math.min(best, m * h[i] - getSum(i + 1 - m, i));
        }
        return best;
    }
	public int minimum(int[] heights) {
        Arrays.sort(heights);
        h = heights;
        n = heights.length;
        s = new int[n];
        for (int i = 0 ; i < n ; i++) {
            if (i > 0)
                s[i] = s[i-1] + h[i];
            else
                s[i] = h[i];
        }
        int res = 0;
        for (int m = 1 ; m <= n ; m ++) {
            res ^= solve(m);
        }
		return res;
	}
}
