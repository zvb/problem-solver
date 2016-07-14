import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class MultiplicationTable2Easy {

	public String isGoodSet(int[] table, int[] t) {

        HashSet<Integer> tSet = new HashSet<Integer>();
        for (int e : t)
            tSet.add(e);


		int n = (int)Math.sqrt(table.length);
		for (int i = 0 ; i < t.length; i++) {
            for (int j = 0 ; j < t.length; j ++) {


                int e1 = t[i], e2 = t[j];
                int res = table[e1 * n + e2];
                if (!tSet.contains(res)) {
                    return "Not Good";
                }

            }
        }
        return "Good";
	}
}
