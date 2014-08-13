#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100100, mod = (int)1e9 + 7;

int a[N], n, u[N], c[N];
int v[N], vn = 0;
long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

long long lcm(long long a, long long b) {
    return a/gcd(a, b) * b;
}

bool sieve[N];

int main() {
    sieve[1] = 1;
    for (int i = 2 ; i < N ; i ++)
        if (!sieve[i]) {
            v[vn ++] = i;
            for (int j = 2 * i ; j < N ; j += i)
                sieve[j] = 1;
        }
    
    
    
    int T;
    scanf("%d ", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1 ; i <= n ; i ++) {
            scanf("%d", &a[i]);
            u[i] = c[i] = 0;
        }
        long long ans = 1;
        for (int i = 1 ; i <= n ; i ++) {
            if (!u[i]) {
                int len = 0;
                int pos = i;
                do {
                    pos = a[pos];
                    u[pos] = 1;
                    len ++;
                } while (pos != i);
                int k = len;
                vector< pair<int, int> > ps;
                for (int j = 0 ; j < vn && v[j] * v[j] <= k; j ++) {
                    if (k % v[j] != 0)
                        continue;
                    ps.push_back(make_pair(j, 0));
                    while (k % v[j] == 0) {
                        ps.back().second ++;
                        k /= v[j];
                    }
                }
                if (k > 1) {
                    int ind = lower_bound(v, v + vn, k) - v;
                    ps.push_back(make_pair(ind, 1));
                }
                for (int i = 0 ; i < ps.size() ; i ++) {
                    c[ps[i].first] = max(c[ps[i].first], ps[i].second);
                }
                
                //ans = lcm(ans, len);
            }
        }
        for (int i = 0 ; i < vn ; i ++) {
            while (c[i]) {
                ans = (ans * v[i]) % mod;
                c[i] --;
            }
        }
        cout << ans << endl;
    }
    return 0;
}