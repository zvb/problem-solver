#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define N 10010
using namespace std;

int n, x[105], dp[105][N], s, p[N];

int main() {
    scanf("%d", &n);
    scanf("%d", &s);
    for (int i = 1 ; i <= n ; i ++) scanf("%d", &x[i]);

    for (int i = 0 ; i <= n ; i ++)
        dp[i][0] = 1;
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= s ; j ++) {
            dp[i][j] = dp[i-1][j];
            if (j >= x[i])
                dp[i][j] |= dp[i-1][j-x[i]];
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    puts(dp[n][s] ? "YES" : "NO");
    
    return 0;
}