#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define N 105
#define M 121200
#define off 30300
using namespace std;
int e[N], w[N], x[N];
int n, m;
int is[M], dp[M];
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &m);
    for (int i = 1 ; i <= m ; i ++)
        scanf("%d%d", &w[i], &e[i]);
    scanf("%d", &n);
    for (int i = 1 ; i <=n ; i ++) {
        scanf("%d", &x[i]);
        x[i] += 2*off;
        is[x[i]] = 1;
    }
    int best = 0;
    for (int i = 0 ; i < M ; i ++) {
        dp[i] = max(dp[i-1], dp[i]);
        if (is[i]) {
            for (int j = 1 ; j <= m ; j++) {
                if (i + e[j] - 1 < M && i - w[j] >= 0) {
                    int &r = dp[i + e[j]];
                    r = max(r, dp[i - w[j]] + 1);
                }
            }
        }
        best = max(best, dp[i]);
    }
    cout << best << endl;
    return 0;
}