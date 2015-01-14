#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

#define filename "diagram"

const int N = 1010, K = 105;

int n, k, a[N];

long long ps[N], u[N][N], dp[N][K];

void calc_u() {
	
	for (int i = 1 ; i <= n ; i ++) {
		multiset<int> up, down;
		long long su = 0, sd = 0;
		up.insert(a[i]);
		su += a[i];
		u[i][i] = 0;
		for (int j = i+1 ; j <= n ; j ++) {
			up.insert(a[j]);
			su += a[j];
			while ((int) up.size() - down.size() >= 2) {
				int go = *up.begin();
				sd += go;
				su -= go;
				down.insert(go);
				up.erase(up.begin());
			}
            multiset<int>::iterator it = --down.end();
            if (*it > *up.begin()) {
                int lo = *it, hi = *up.begin();
                sd -= lo; sd += hi;
                su -= hi; su += lo;
                down.erase(it);
                up.erase(up.begin());
                down.insert(hi);
                up.insert(lo);
            }
			int med = *up.begin();
			int diff = (int) up.size() - down.size();
			u[i][j] = su - sd - 1ll * med * (diff);
            /*
            if (i == 1 && j == 3) {
                cout << "su, sd = " << su << ' ' << sd << '\n';
                cout << "size = " << up.size() << ' ' << down.size() << endl;
                cout << "med = " << med << ' ' << diff << '\n';
                cout << u[i][j] << " " ;
            }
             */
            //cout << u[i][j] << " " ;
		}
		//cout << endl;
	}
}

int main() {
	assert(freopen(filename ".in", "r", stdin));
	assert(freopen(filename ".out", "w", stdout));
	scanf("%d%d", &n, &k);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d", &a[i]);
		ps[i] = ps[i-1] + a[i];
	}
	calc_u();
    
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= k ; j++) {
			if ( j == 0 ) {
				dp[i][j] = u[1][i];
				continue;
			}
			dp[i][j] = dp[i][j-1];
			for (int l = 0 ; l < i ; l ++) {
				dp[i][j] = min(dp[l][j-1] + u[l + 1][i], dp[i][j]);
			}
		}
	}
	cout << dp[n][k] << endl;
    
    
	return 0;
}