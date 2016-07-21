import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class TreeAndVertex {
	
	public int get(int[] tree) {
		int n = tree.length;
		int d[] = new int [n+1];
        for (int i = 0 ; i < n ; i ++) {
            int from = i + 1, to = tree[i];
            d[from] ++;
            d[to] ++;
        }
        int idx = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (d[idx] < d[i])
                idx = i;
        }
        return d[idx];
	}
}
