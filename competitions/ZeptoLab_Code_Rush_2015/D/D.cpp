#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = (int)1e6 + 100;
/*
7 2
bcabcab
*/



void z_function (char *s, int *z, int n) {
	
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	z[0] = n;
}

int n, k;
char s[N];
int z[N];
int ok[N];
int ok1[N];
char ans[N];

int main() {
	scanf("%d%d ", &n, &k);
	gets(s);
	z_function(s, z, n);

	for (int i = 0 ; i < n ; i ++)
		cout << z[i] << ' ';
		cout << endl;	

	for (int d = 1; d <= n ; d ++) {
		
		
		for (int i = 0, kk =0 ; i < n ; i += d, kk ++) {
			if (z[i] < d) {
				ok[d] = kk;
				break;
			}

		}
	}
	for (int i = 1 ; i < n ; i ++)
		cout << ok[i] << ' ';
		cout << endl;	

	int d = 1;
	for (int i = 0 ; i < n ; i ++) {
		ans[i] = '0';
		int d1 = (i + 1) / (k + 1);
		int d2 = (i + 1) / (k);
		cout << d1 << ' ' << d2 << endl;
		if (1ll * d1 * (k + 1) <= (i + 1)) {
			if (ok[d1] >= k + 1)
				ans[i] = '1';
		}
		if (ok[d2] >= k && z[k * d] >= i - k * d + 1)
			ans[i] = '1';

	}
	puts(ans);



	return 0;
}