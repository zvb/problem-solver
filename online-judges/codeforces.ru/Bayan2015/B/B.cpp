#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 25;

int u[N][N];

int n, m;
char h[N], v[N];

void dfs(int i, int j) {
    if (u[i][j]) return;
    if (i < 1 || i > n) return;
    if (j < 1 || j > m) return;
    u[i][j] = 1;
    if (h[i] == '>')
        dfs(i, j + 1);
    else
        dfs(i, j - 1);
    if (v[j] == '^')
        dfs(i-1, j);
    else
        dfs(i+1, j);
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s\n%s", h + 1, v + 1);
//    cout << strlen(h+1) << ' ' << strlen(v +1);
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j ++) {
            memset(u, 0, sizeof(u));
            dfs(i, j);
            for (int ii = 1 ; ii <= n ; ii ++) {
                for (int jj = 1 ; jj <= m ; jj ++)
                    if (!u[ii][jj]) {
                        puts("NO");
                        return 0;
                    }
            }
        }
    }
    puts("YES");
    
    return 0;
}
