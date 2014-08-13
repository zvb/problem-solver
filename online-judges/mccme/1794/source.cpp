#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define N 100100
using namespace std;

int n, a[N], k, b, m;
int dp[N], p[N], l[N];
int v[N], vn = 0;

int main() {
    scanf("%d%d%d%d%d", &n, &a[1], &k, &b, &m);
    //cout << a[1] << ' ';
    for (int i = 2 ; i <= n ; i ++) {
        a[i] = ( k * a[i-1] + b ) % m;
        dp[i] = 1 << 30;
        //cout << a[i] << ' ';
    }
    //cout << endl;
    dp[0] = -1; dp[1] = 1 << 30;
    for (int i = 1 ; i <= n ; i ++) {
        int pos = upper_bound(dp, dp + n + 1, a[i]) - dp;
        if (dp[pos] > a[i] && a[i] > dp[pos - 1]) {
            dp[pos] = a[i];
            l[pos] = i;
            p[i] = l[pos-1];
            //cout << "i = " << i << " pos = " << pos << endl;
        }
    }
    int ans = 0;
    for (int i = 1;  i <= n ; i ++) {
        if (dp[i] < (1 << 30)) ans = i;
    }
    for (int i = l[ans] ; i > 0 ; i = p[i]) {
        v[vn ++] = a[i];
    }
    for (int i = vn - 1 ; i >= 0 ; i --)
        printf("%d ", v[i]);
    puts("");
    
    return 0;
}