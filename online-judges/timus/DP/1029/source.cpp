#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 500
#define M 100
using namespace std;

int n, m, c[M][N];
long long s[M][N], dp[M][N];
long long memo[N][N];
int found[N][N];
int p[N][N];

long long rec(int j, int k, int i) {
    if (found[j][k]) return memo[j][k];
    found[j][k] = 1;
    if (j == k) {
        p[j][k] = 1;
        return memo[j][k] = dp[i-1][k] + c[i][j];
    }
    if (j < k) {
        memo[j][k] = dp[i-1][k] + c[i][j] + s[i - 1][k-1] - s[i - 1][j-1];
        p[i][k] = 1; // up
        long long rel = c[i][j] + rec(j + 1, k, i);
        if (rel < memo[j][k]) {
            memo[j][k] = rel;
            p[i][k] = 2; // right
        }
        return memo[j][k];
    } else {
        memo[j][k] = dp[i-1][k] + c[i][j] + s[i - 1][j] - s[i-1][k];
        p[j][k] = 1;
        long long rel = rec(j-1, k, i) + c[i][j];
        if (memo[j][k] > rel)
            memo[j][k] = rel, p[j][k] = 3; // left
        return memo[j][k];
    }
}
int v[N], vn = 0;

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1 ; i <= m ; i ++) {
        for (int j = 1 ; j <= n ; j ++) {
            scanf("%d", &c[i][j]);
            s[i][j] = s[i][j-1] + c[i][j];
        }
    }
    for (int i = 1 ; i <= m ; i++) {
        memset(found, 0, sizeof(found));
        memset(p, 0, sizeof(p));
        for (int j = 1 ; j <= n ; j ++) {
            long long &r = dp[i][j];
            r = 1ll << 60;
            int _k = -1;
            for (int k = 1; k <= n ; k ++) {
                long long rel = rec(j, k, i);
                if (r > rel)
                    r = rel, _k = k;
            }
            
            vn = 0;
            int pos = j;
            do {
                v[vn ++] = pos;
                if (p[pos][_k] == 1) {
                    for ( ; pos != _k ; pos += (_k < pos ? -1 : 1)) {
                        v[vn ++] = pos;
                    }
                } else {
                    if (p[pos][_k] == 3)
                        pos --;
                    else
                        pos ++;
                }
            } while (pos != _k);
            for (int )
            printf("%02lld ", dp[i][j]);
        }
        cout << endl;
    }
    long long best = 1ll << 60;
    for (int j = 1 ; j <= n ; j++)
        best = min(best, dp[m][j]);
    cout << best << endl;

    return 0;
}