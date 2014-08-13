#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define N 1001000
using namespace std;

int n, x[105], dp[N], s, p[N];

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i ++) scanf("%d", &x[i]);
    scanf("%d", &s);
    sort(x + 1, x + n + 1);
    for (int i = 1 ; i <= s ; i ++) {
        dp[i] = 1 << 30;
        for (int j = 1 ; j <= n && x[j] <= i ; j ++) {
            if (dp[i] > dp[i-x[j]] + 1) {
                dp[i] = dp[i-x[j]] + 1;
                p[i] = x[j];
            }
        }
    }
    if (dp[s] >= (1 << 30)) {
        puts("No solution");
        return 0;
    }
    int ss = s;
    for (int ss = s ; ss > 0 ; ss = ss - p[ss]) {
        printf("%d ", p[ss]);
    }
    puts("");
    
    return 0;
}