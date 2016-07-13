import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class Starport {

	public int gcd(int x, int y) {
		if (x == 0) return y;
		return gcd(y%x, x);
	}
	public double getExpectedTime(int N, int M) {
		int d = gcd(N, M);
		int n = N / d, m = M / d;
		double result = 1.0 * (n-1) * d/2;
		return result;
	}
}
