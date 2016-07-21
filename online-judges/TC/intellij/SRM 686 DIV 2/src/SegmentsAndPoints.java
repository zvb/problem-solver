import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class SegmentsAndPoints {
	
	public String isPossible(int[] p, int[] l, int[] r) {
        Arrays.sort(p);
        int n = l.length;


        boolean used[] = new boolean[n];
        for (int x : p) {
            int idx = -1;
            for (int i = 0 ; i < n ; i++) {
                if (used[i] || x < l[i])
                    continue;

                if (x <= r[i] && (idx == -1 || r[i] < r[idx]) )
                    idx = i;
            }
            if (idx == -1)
                return "Impossible";
            used[idx] = true;
        }

		return "Possible";
	}
}
