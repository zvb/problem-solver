#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int mod = 1000000007;

int n, m[11][101], dp[101][1 << 10];

void solve() {
    scanf("%d ", &n);
    char c;
    int x;
    memset(m, 0, sizeof(m));
    memset(dp, 0, sizeof(dp));
    for (int i = 0 ; i < n ; i ++) {
        while (1) {
            scanf("%d%c", &x, &c);
            m[i][x] = 1;
            if (c != ' ')
                break;
        }
    }
    dp[0][0] = 1;
    for (int i = 0 ; i < 100 ; i ++) {
        for (int mask = 0 ; mask < (1 << n) ; mask ++) {
            int &r = dp[i+1][mask];
            r += dp[i][mask]; if (r >= mod) r -= mod;
            for (int j = 0 ; j < n ; j ++) {
                if (!(mask & (1 << j)) && m[j][i + 1]) {
                    int &ref = dp[i+1][mask | (1 << j)];
                    ref += dp[i][mask];
                    if (ref >= mod) ref -= mod;
                }
            }
        }
    }
    printf("%d\n", dp[100][(1 << n) - 1]);
    
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t --) {
        solve();
    }
    return 0;
}