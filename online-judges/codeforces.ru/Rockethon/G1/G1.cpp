#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

const int N = 33, K = 222;

int n, k;

double dp[N][N][K];

int a[N];

double mul;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1 ; i <= n ; i ++) {
        scanf("%d", &a[i]);
        dp[a[i]][i][0] = 1.0;
    }
    mul = 2.0 / (n * (n + 1));
    
    for (int kk = 1 ; kk <= k ; kk ++) {
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= n ; j ++) {
                for (int l = 1 ; l <= n ; l ++) {
                    for (int r = l ; r <= n ; r ++) {
                        if (j < l || j > r)
                            dp[i][j][kk] = dp[i][j][kk-1] * mul;
                        else
                            dp[i][l + r - j][kk] = dp[i][j][kk-1] * mul;
                    }
                }
            }
        }
    }
    
    double ans = 0.0;
    printf("%.12lf\n", ans);
   
    
    
    return 0;
}