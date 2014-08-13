#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int lim = (int)1e7;

long long brute(int n, int m, int k) {
    long long res = 0;
    for (int i = 0 ; i <= n - 1 && i < lim; i ++) {
        if ( k > i ) break;
        res = max(res, 1ll * (n / (i + 1)) * (m / (k - i + 1)));
    }
    return res;
}

long long solve(int n, int m, int k) {
    if (k > n - 1) {
        k -= n - 1;
        long long ans = m / ( k + 1 );
        return ans;
    } else {
        //cerr << n << ' ' << m << endl;
        long long ans = 1ll * ( n / (k + 1) ) * m;
        return ans;
    }
    
}

int n, m, k;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    if (n < m) swap(n, m);
    if (k > n - 1 + m - 1) {
        puts("-1");
        return 0;
    }
    long long s1 = max(solve(n, m, k), solve(m, n, k));
    long long s2 = max(brute(n, m, k), brute(m, n, k));
    cout << max(s1, s2) << endl;
    
    
    return 0;
}