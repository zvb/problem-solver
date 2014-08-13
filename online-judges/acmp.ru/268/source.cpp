#include <iostream>
#include <cstdlib>
#include <cstdio>  
#include <algorithm>
#define N 5005
using namespace std;

int n, k, dp[N], db[N];
char s[N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d ", &n, &k);
    gets(s);
    int ans = n;
    for (int len = 2 ; len <= n ; len += 2) {// for even
        for (int i = 0 ; i + len <= n ; i ++) {
            if (s[i] == s[i + len - 1])
                db[i] = dp[i+1];
            else
                db[i] = dp[i+1] + 1;
            if (db[i] <= k)
                ans ++;
        }
        for (int i = 0 ; i + len <= n ; i++)
            dp[i] = db[i];
    }
    for (int i = 0 ; i <= n ; i ++)
        dp[i] = db[i] = 0;
    for (int len = 3 ; len <= n ; len += 2) {
        for (int i = 0 ; i + len <= n ; i ++) {
            if (s[i] == s[i + len - 1])
                db[i] = dp[i+1];
            else
                db[i] = dp[i+1] + 1;
            if (db[i] <= k)
                ans ++;
        }
        for (int i = 0 ; i + len <= n ; i++)
            dp[i] = db[i];
    }
    
    
    
    cout << ans << endl;
    return 0;
}