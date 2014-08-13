#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define N 1005

using namespace std;

int n, dp[N][N], p[N][N];
int s1[N], s2[N];
char str1[N], str2[N];
char ans[2*N];
int main() {
    scanf("%d ", &n);
    gets(str1 + 1);
    for (int i = 1 ; i <= n ; i++) {
        if (str1[i] == '1')
            s1[i] = s1[i-1] + 1;
        else
            s1[i] = s1[i-1];
    }
    gets(str2 + 1);
    for (int i = 1 ; i <= n ; i++) {
        if (str2[i] == '1')
            s2[i] = s2[i-1] + 1;
        else
            s2[i] = s2[i-1];
    }
    dp[0][0] = 1;
    for (int i = 0 ; i <= n ; i ++) {
        for (int j = 0 ; j <= n ; j ++) {
            if (!i && !j) continue;
            int ones = s1[i] + s2[j], zeros = i + j - ones;
            //cout << "i = " << i << " j = " << j << endl;
            //cout << "ones = " << ones << " zeros = " << zeros << endl;
            if (abs(ones - zeros) <= 1 &&
                ( (i > 0 && dp[i-1][j]) || (j > 0 && dp[i][j-1]) ) )
            {
                dp[i][j] = 1;
            }
            if (dp[i-1][j]) {
                p[i][j] = 1;
            }
            if (dp[i][j-1])
                p[i][j] = 2;
        }
    }
    /*
    for (int i = 0 ; i <= n ; i ++) {
        for (int j = 0 ; j <= n ; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    for (int i = 0 ; i <= n ; i ++) {
        for (int j = 0 ; j <= n ; j++)
            cout << p[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
     */
    if (!dp[n][n]) {
        puts("Impossible");
        return 0;
    }

    
    int pos = 0, i = n, j = n;
    while (i != 0 || j != 0) {
        if (p[i][j] == 1) {
            i --;
            ans[pos] = '1';
        }
        else {
            j --;
            ans[pos] = '2';
        }
        pos ++;
    }
    for (int i = pos - 1 ; i >= 0 ; i --)
        putchar(ans[i]);
    puts("");

    return 0;
}