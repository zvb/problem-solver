import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class RGBTree {


    char memo[][][][] ;
    String [] G ;
    int n;
    public final static int C = 5, N = 13;


	public String exist(String[] G) {
        memo = new char[C][C][C][1 << N];
        this.G = G;
        this.n = G.length;
        int p = (n - 1)/3;

        for (int i = 0; i < C; i++) {
            for (int j = 0 ; j < C ; j++) {
                for (int k = 0 ; k < C ; k++) {
                    Arrays.fill(memo[i][j][k], 'N');
                }
            }
        }
        memo[0][0][0][0] = 'Y';
        for (int i = 0 ; i < n ; i++)
            memo[0][0][0][1 << i] = 'Y';

        //System.out.println("n = " + n + ", p = " + p);
        for (int mask = 0 ; mask < (1 << n) ; mask ++) {
            for (int ri = 0 ; ri <= p ; ri++) {
                for (int gi = 0 ; gi <= p ; gi ++) {
                    for (int bi = 0 ; bi <= p ; bi ++) {
                        if (memo[ri][gi][bi][mask] != 'Y')
                            continue;

                        //System.out.println(ri + " " + gi + " " + bi + " " + mask);

                        for (int i = 0 ; i < n ; i++) {
                            if ((mask & (1 << i)) > 0) {
                                for (int j = 0 ; j < n ; j++) {
                                    if ( (mask & (1 << j)) == 0 ) {
                                        char col = G[i].charAt(j);
                                        if (col == '.')
                                            continue;
                                        //System.out.println("going over edge " + i + " " + j + " " + col);
                                        int nr = ri + (col == 'R' ? 1 : 0);
                                        int ng = gi + (col == 'G' ? 1 : 0);
                                        int nb = bi + (col == 'B' ? 1 : 0);
                                        if (nr < C && ng < C && nb < C)
                                            memo[nr][ng][nb][mask | (1 << j)] = 'Y';
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }



        if (memo[p][p][p][(1 << n) - 1] == 'Y')
            return "Exist";

		return "Does not exist";
	}
}
