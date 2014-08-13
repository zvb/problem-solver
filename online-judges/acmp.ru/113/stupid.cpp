#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1005;

int u[N][N];
char g[N][N];
int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d ", &n);
    for (int i = 1 ; i <= n ; i ++)
        gets(g[i] + 1);
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= n ; j ++) {
            u[i][j] = u[i-1][j] + u[i][j-1] - u[i-1][j-1] + (g[i][j] == '1');
            //cout << u[i][j] << ' ';
        }
        //cout << endl;
    }
    int best = 0;
    for (int i1 = 1 ; i1 <= n ; i1 ++) {
        for (int j1 = 1 ; j1 <= n ; j1 ++) {
            if (g[i1][j1] != '1')
                continue;
            int lo = 0, hi = n - max(i1, j1), k;
            while (hi > lo) {
                k = (hi + lo + 1) / 2;
                int sum = u[i1 + k][j1 + k] - u[i1-1][j1+k] - u[i1+k][j1-1]+u[i1-1][j1-1];
                if (sum < (k+1)*(k+1))
                    hi = k - 1;
                else
                    lo = k;
            }
            best = max(best, (lo + 1) * (lo + 1));
        }
    }
    
    cout << best << endl;
    
    return 0;
}