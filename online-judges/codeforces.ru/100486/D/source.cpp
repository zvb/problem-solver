#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2002;


int dup[N][N], lup[N][N], dleft[N][N], lleft[N][N];
int dp[N][N];

int getHor(int a[N][N], int n, int m) {
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j++) {
            if (i == 1) {
                dup[i][j] = 0;
                lup[i][j] = 1;
            } else if (i == 2) {
                dup[i][j] = a[i][j] - a[i-1][j];
                lup[i][j] = 2;
            } else {
                dup[i][j] = a[i][j] - a[i-1][j];
                if (dup[i-1][j] == dup[i][j])
                    lup[i][j] = lup[i-1][j] + 1;
                else
                    lup[i][j] = 2;
            }
            if (j == 1) {
                dleft[i][j] = 0;
                lleft[i][j] = 1;
            } else if (j == 2) {
                dleft[i][j] = a[i][j] - a[i][j-1];
                lleft[i][j] = 2;
            } else {
                dleft[i][j] = a[i][j] - a[i][j-1];
                if (dleft[i][j-1] == dleft[i][j])
                    lleft[i][j] = lleft[i][j-1] + 1;
                else
                    lleft[i][j] = 2;
            }
        }
    }
    int res = 1;
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m; j ++) {
            if (i == 1 || j == 1) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = 1;
            
            if (dup[i][j] == 0 || dleft[i][j] == 0 || dup[i][j] == dleft[i][j] || dup[i][j] == -dleft[i][j])
            {
                int len = min(lleft[i][j], lup[i][j]);
                if (dleft[i][j] == dleft[i-1][j] && dup[i][j] == dup[i][j-1]) {
                    dp[i][j] = 2;
                    if (len >= 3) {
                        if (dleft[i][j] == dleft[i-1][j-1] && dup[i][j] == dup[i-1][j-1])
                            dp[i][j] = max(dp[i][j], min(dp[i-1][j-1] + 1, len));
                    }
                }
            }
            if (res < dp[i][j]) {
                res = dp[i][j];
                //cerr << i << ' ' << j << ' ' << res << endl;
            }
        }
    }
    return res*res;
}

int n, m, a[N][N];


int main() {
    while (1) {
        scanf("%d%d", &n, &m);
        if (!n && !m) break;
        for (int i = 1 ; i <= n ; i ++)
            for (int j = 1 ; j <= m ; j++)
                scanf("%d", &a[i][j]);
        printf("%d\n", getHor(a, n, m));
/*
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j++)
                printf("%d ", dp[i][j]);
            puts("");
        }
*/
    }
    
    return 0;
}