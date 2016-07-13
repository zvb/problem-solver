#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int lim = 100;

long long f(long long x, long long y, long long hr, long long hb) {
	return hr * x + y * hb;
}

long long solve(long long c, long long hr, long long hb, long long wr, long long wb) 
{
	long long ymax = c / wb;
	long long ymin = 0;
	long long y = -1;
	if (hb * wr >=  hr * wb) {
		y = ymax;
	} else {
		y = ymin;
	}
	long long best = 0;
	for (long long h = max(0ll, y - lim); h <= min(ymax, y + lim); h ++) {
		long long x = (c - h * wb) / wr;
		best = max(best, f(x, h, hr, hb));
	}
	return best;
}

long long c, hr, hb, wr, wb;



int main() {
	cin >> c >> hr >> hb >> wr >> wb;
	cout << max(solve(c, hr, hb, wr, wb), solve(c, hb, hr, wb, wr)) << endl;
	

	return 0;
}