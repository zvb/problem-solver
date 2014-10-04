#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;



int w[111], W, n;
int dp[111][100111], p[111][100111];

int main() {
    scanf("%d%d", &W, &n);
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    W = sum - W;
    dp[0][0] = 1;
    for (int i = 0 ; i < n ; i ++) {
        for (int j = W ; j >= 0 ; j --) {
            dp[i+1][j] += dp[i][j]; if (dp[i+1][j] >= 2) dp[i+1][j] = 2;
            if (j + w[i + 1] <= W) {
                dp[i + 1][j + w[i + 1]] += dp[i][j];
                if (dp[i + 1][j + w[i + 1]] >= 2)
                    dp[i + 1][j + w[i + 1]] = 2;
            }
        }
    }
    if (dp[n][W] == 0)
        puts("0");
    else if (dp[n][W] != 1)
        puts("-1");
    else {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = W ; j >= 0; j --) {
                if (dp[i][j]) {
                    dp[i+1][j] |= dp[i][j];
                    if (j + w[i + 1] <= W) {
                        dp[i + 1][j + w[i + 1]] |= dp[i][j];
                        p[i + 1][j + w[i + 1]] = i+1;
                    }
                }
            }
        }
        int ii = n, jj = W;
        vector<int> ans;
        while (ii > 0 && jj > 0) {
            if (p[ii][jj] == 0)
                ;
            else {
                ans.push_back(p[ii][jj]);
                jj -= w[p[ii][jj]];
            }
            ii --;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0 ; i < ans.size() ; i ++)
            printf("%d ", ans[i]);
        puts("");
    }
    
    return 0;
}