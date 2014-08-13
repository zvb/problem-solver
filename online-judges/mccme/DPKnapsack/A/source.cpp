#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define N 1001000
using namespace std;

int n, c[N], dp[N], cn = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1, j = 0 ; (j = i * i * i) <= n ; i ++) {
        c[i] = j;
        cn = i;
    }
    for (int i = 1; i <= n; i ++) {
        dp[i] = 1 << 30;
        for (int j = cn ; j >= 1 ; j --) {
            if (i - c[j] >= 0 && dp[i-c[j]] + 1 < dp[i])
                dp[i] = dp[i-c[j]] + 1;
        }
    }
    cout << dp[n] << endl;
   
    
    return 0;
}