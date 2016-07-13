#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = (1 << 10) + 10;

int n, m;
int a[N];

long long ans = 0;

int rec(int v) {
	if (m/2 <= v && v < m) { // leaf
		return 0;
	}
	int l = rec(2*v), r = rec(2*v+1);
	int total = max(l + a[2*v], r + a[2*v+1]);
	//cout << "a " << a[2*v] << ' ' << a[2*v+1] << endl;
	//cout << "v = " << v << " l = " << l << " r = " << r << " total = " << total << endl;
	ans += 2*total - (l + a[2*v]) - (r + a[2*v+1]);
	//cout << "ans = " << ans << endl;
	return total;
}

int main() {
	scanf("%d", &n);
	m = 1 << (n + 1);
	for (int i = 2 ; i < m; i ++) {
		scanf("%d", &a[i]);
	}
	rec(1);
	cout << ans << endl;

	return 0;
}