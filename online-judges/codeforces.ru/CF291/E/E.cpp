#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

const int N = 111, mod = (int)1e9 + 7;



struct Mat {
	int n, m;
	int **a;
	Mat() {}
	Mat(int _n, int _m) {
		//cout << "Called Mat()\n";
		n = _n; m = _m;
		a = new int* [n];
		for (int i = 0 ; i < n ; i++) {
			a[i] = new int[m];
			for (int j = 0 ; j < m ; j ++) {
				a[i][j] = 0;
			}
		}
		//cout << "finishin Mat()\n";
	}
	Mat operator*(const Mat& r) const {
		assert(m == r.n);
		Mat res(n, r.m);
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < r.m ; j ++) {
				for (int k = 0 ; k < m ; k ++) {
					res.a[i][j] = (res.a[i][j]  + 1ll * a[i][k] * r.a[k][j] % mod) % mod;
				}
			}
		}
		return res;
	}
	void print(int lim = 5) {
		for (int i = 0 ; i < min(n, lim) ; i ++) {
			for (int j = 0 ; j < min(m, lim) ; j ++) {
				printf("%d ", a[i][j]);
			}
			puts("");
		}
		puts("");
	}
	/*
	~Mat() {
		for (int i = 0 ; i < n ; i ++) {
			delete a[i];
		}
		delete a;
	}
	*/

};

Mat bin_pow(Mat x, int p) {
	//cout << "bin_pow " << p << endl;
	Mat res(x.n, x.n);
	for (int i = 0 ; i < x.n ; i ++) {
		res.a[i][i] = 1;
	}
	while (p) {
		if (p & 1) 
			res = res * x;
		x = (x * x);
		p >>= 1;
	}
	return res;
}

int c[N];
int n, m;
int f[N], g[N];



Mat A(101, 101);

int calc(int n) {
	if (n < 101) {
		return g[n];
	}
	//cout << "here\n";
	Mat v(101, 1);
	v.a[0][0] = g[100];
	for (int i = 1 ; i < 101 ; i ++) {
		v.a[i][0] = f[100 - i + 1];
	}
	//cout << "here\n";
	Mat u = bin_pow(A, n - 100) * v;
	//A.print(); v.print(); u.print();
	//cout << "here\n" << u.n << ' ' << u.m << endl;
	return u.a[0][0];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0 ; i < n ; i ++) {
		int x;
		scanf("%d", &x);
		c[x] ++;
	}
	f[0] = g[0] = 1;
	for (int i = 1 ; i < N ; i++) {
		for (int j = 1 ; j <= i && j <= 100 ; j ++) {
			f[i] = (f[i] + 1ll * f[i-j] * c[j] % mod) % mod;
		}
		g[i] = (g[i-1] + f[i])%mod;
	}
	//cout << "here\n";

	A.a[0][0] = 1;

	for (int i = 1 ; i < 101; i ++) {
		A.a[0][i] = A.a[1][i] = c[i];
	}
	for (int i = 2 ; i < 101 ; i++) {
		A.a[i][i-1] = 1;
	}
	
	printf("%d\n", calc(m));
	return 0;
}