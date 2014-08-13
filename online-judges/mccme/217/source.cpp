#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char a[100], b[100];
int dp[100][100], an, bn;
int f[100][100];
int di[] = {0, -1, -1};
int dj[] = {-1, -1, 0};
char ans[100];
int n = 0;

int main() {
    gets(a + 1); gets(b + 1);
    an = strlen(a + 1);
    bn = strlen(b + 1);
    for (int i = 0 ; i <= an ; i ++) {
        for (int j = 0 ; j <= bn ; j ++) {
            if (!i && !j) {
                //printf("%d ", dp[i][j] < (1 << 30) ? dp[i][j] : -1);
                continue;
            }
            int &r = dp[i][j];
            r = 1 << 30;
            if (a[i] == '*') {
                if (r > dp[i-1][j]) {
                    r = dp[i-1][j];
                    f[i][j] = 2;
                }
                if (j > 0 && r > dp[i-1][j-1]) {
                    r = dp[i-1][j-1] + 1;
                    f[i][j] = 1;
                }
                if (j > 0 && r > dp[i][j-1] + 1) {
                    r = dp[i][j-1] + 1;
                    f[i][j] = 0;
                }
                
            }
            if (b[j] == '*') {
                if (r > dp[i][j-1]) {
                    r = dp[i][j-1];
                    f[i][j] = 0;
                }
                if (i > 0 && r > dp[i-1][j-1]) {
                    r = dp[i-1][j-1] + 1;
                    f[i][j] = 1;
                }
                if (i > 0 && r > dp[i-1][j] + 1) {
                    r = dp[i-1][j] + 1;
                    f[i][j] = 2;
                }
            }
            if (j > 0 && a[i] == '?') {
                if (r > dp[i-1][j-1] + 1) {
                    r = dp[i-1][j-1] + 1;
                    f[i][j] = 1;
                }
            }
            if (i > 0 && b[j] == '?') {
                if (r > dp[i-1][j-1] + 1) {
                    r = dp[i-1][j-1] + 1;
                    f[i][j] = 1;
                }
            }
            if (i > 0 && j > 0 && a[i] != '?' && a[i] != '*' &&
                b[j] != '?' && b[j] != '*') {
                if (a[i] == b[j]) {
                    if (r > dp[i-1][j-1] + 1) {
                        r = dp[i-1][j-1] + 1;
                        f[i][j] = 1;
                    }
                }
            }
            //printf("%d ", dp[i][j] < (1 << 30) ? dp[i][j] : -1);
        }
        //puts("");
    }
    if (dp[an][bn] >= (1 << 30)) {
        puts("No solution!");
        return 0;
    }
    /*
    for (int i = 0 ; i <= an ; i ++) {
        for (int j = 0 ; j <= bn ; j ++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
    */
    int ii = an, jj = bn;
    while (ii && jj) {
        if (f[ii][jj] == 1) {
            ans[n] = 'a';
            if (a[ii] != '?' && a[ii] != '*')
                ans[n] = a[ii]; // what if ii == 0?
            if (b[jj] != '?' && b[jj] != '*')
                ans[n] = b[jj];
            n ++;
            ii --; jj --;
        } else {
            if (a[ii] == '*' && b[jj] == '*') {
                
            } else {
                if ( (a[ii] == '*' && f[ii][jj] == 0) ||
                    (b[jj] == '*' && f[ii][jj] == 2) ) {
                    ans[n] = 'a';
                    if (a[ii] != '*' && a[ii] != '?')
                        ans[n] = a[ii];
                    if (b[jj] != '*' && b[jj] != '?')
                        ans[n] = b[jj];
                    n ++;
                }
            }
            int new_ii = ii + di[f[ii][jj]];
            int new_jj = jj + dj[f[ii][jj]];
            ii = new_ii;
            jj = new_jj;
        }
    }
    for (int i = n - 1 ; i >= 0 ; i --)
        putchar(ans[i]);
    puts("");
    
    
    
    return 0;
}