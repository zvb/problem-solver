#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 305;

int t = 1;
map<int, int> ind;

int n;
int a[N];

vector<int> g[N];
int c[N];


// TODO!!
int dp[N][N*N];
int taken[N][N*N];

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        int aa = a[i];
        for (int j = 2 ; j * j <= aa; j ++) {
            if (aa % j == 0) {
                if (ind.count(j) == 0) {
                    ind[j] = t ++;
                } else {
                    
                }
                while (aa % j == 0) {
                    aa /= j;
                }
            }
        }
        if (aa > 1) {
            if (ind.count(aa) == 0)
                ind[aa] = t ++;
        }
    }
    for (int i = 1 ; i <= n ; i++)
        scanf("%d", &c[i]);
    
    
    for (int i = 1; i <= n ; i ++) {
        g[i].resize(t + 1);
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (map<int, int>::iterator it = ind.begin() ; it != ind.end() ; it++) {
            int p = it->first;
            int idx = it->second;
            if (a[i] % p == 0) {
                g[i][idx] = 1;
            }
        }
    }
    
    for (int i = 1; i < t ; i ++) {
        dp[0][i] = 1 << 30;
    }
    
    
    for (int i = 1;  i <= n ; i ++) {
        for (int j = 1 ; j < t ; j ++)
            printf("%d ", g[i][j]);
        puts("");
    }
    for (int i = 1; i < t ; i ++) {
        dp[0][i] = 1 << 30;
    }
    for (int i = 1 ; i < t ; i ++) {
        for (int j = 1 ; j <= n ; j ++) {
            taken[j][i] = taken[j][i-1];
            dp[j][i] = dp[j-1][i];
            if (taken[j][i]) {
                
                cout << "taken " << j << ' ' << i << endl;
            }
            if (taken[j][i]) {
                dp[j][i] = min(dp[j][i], dp[j][i-1]);
            }
            if (g[j][i] == 0) {
                
                if (dp[j][i] > dp[j-1][i-1] + c[j]) {
                    dp[j][i] =  dp[j-1][i-1] + c[j];
                    taken[j][i] = 1;
                }
                
            }
            //printf("%d ", dp[j][i] < (1 << 30) ? dp[j][i] : -1);
        }
        //puts("");
    }
    
    for (int j = 1 ; j <= n ; j ++) {
        for (int i = 1 ; i < t ; i ++) {
            
            
            printf("%d ", dp[j][i] < (1 << 30) ? dp[j][i] : -1);
        }
        puts("");
    }
    
    printf("%d\n", dp[n][t-1]);
    
    return 0;
}