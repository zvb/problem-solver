#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 200;
int n, a[N], k, s[N];
int dp[N][N];

int memo[N][N], c[N][N];

int rec(int I, int K) {
    if (I <= 0)
        return 0;
    if (I == 1)
        return a[1];
    if (c[I][K])
        return memo[I][K];
    c[I][K] = 1;
    
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    scanf("%d", &k);
    
    
    
    return 0;
}