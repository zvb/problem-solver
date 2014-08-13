#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n, k, a[111];
long long dp[111][11111];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    long long s = 0;
    for (int i = 1 ; i <= n ; i ++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    if (s < 2*k) {
        puts("0");
        return 0;
    }
    
    dp[0][0] = 1;
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 0 ; j <= k ; j ++) {
            dp[i][j] += dp[i-1][j];
            if (j - a[i] >= 0)
                dp[i][j] += dp[i-1][j-a[i]];
        }
    }
    long long a1 = 0;
    for (int i = 0 ; i < k ; i ++)
        a1 += dp[n][i];
    long long ans = (1ll << n) - 2*a1;
    cout << ans << endl;
    
    
    return 0;
}