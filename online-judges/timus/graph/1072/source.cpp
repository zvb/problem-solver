#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 100, INF = 1 << 30;

int g[N][N];
int ip[N][5], mask[N][5];
int num[N];

int d[N], p[N], s, t;

int n;
int tmp[4];

priority_queue< pair<int, int > > q;

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i ++) {
        scanf("%d", &num[i]);
        for (int j = 0 ; j < num[i]; j ++) {
            int a, b;
            scanf("%d.%d.%d.%d", tmp, tmp + 1, tmp + 2, tmp + 3);
            a = (tmp[0] << 24) + (tmp[1] << 16) + (tmp[2] << 8) + tmp[3];
            scanf("%d.%d.%d.%d", tmp, tmp + 1, tmp + 2, tmp + 3);
            b = (tmp[0] << 24) + (tmp[1] << 16) + (tmp[2] << 8) + tmp[3];
            ip[i][j] = a;
            mask[i][j] = b;
        }
    }
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j ++) {
            if (i != j)
                g[i][j] = INF;
            else
                g[i][j] = 0;
        }
    
    for (int i = 1; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j ++) {
            for (int k1 = 0 ; k1 < num[i]; k1 ++) {
                for (int k2 = 0 ; k2 < num[j] ; k2 ++) {
                    if ( (ip[i][k1] & mask[i][k1] ) == ( ip[j][k2] & mask[j][k2] ) ) {
                        g[i][j] = 1;
                    }
                }
            }
        }
    }
    scanf("%d%d", &s, &t);
    for (int i = 1 ; i <= n ; i ++)
        d[i] = INF, p[i] = -1;
    d[s] = 0;
    q.push(make_pair(-d[s], s));
    while (!q.empty()) {
        int v = q.top().second, dist = -q.top().first;
        q.pop();
        if (d[v] != dist) continue;
        for (int i = 1 ; i <= n ; i ++) {
            if (g[v][i] < INF && d[i] > d[v] + g[v][i]) {
                d[i] = d[v] + g[v][i];
                p[i] = v;
                q.push(make_pair(-d[i], i));
            }
        }
    }
    if ( d[t] < INF ) {
        vector<int> ans;
        int c = p[t];
        ans.push_back(t);
        while (c != -1) {
            ans.push_back(c);
            c = p[c];
        }
        puts("Yes");
        for (int i = (int)ans.size() - 1 ; i >= 0 ; i --)
            printf("%d ", ans[i]);
        puts("");
    } else
        puts("No");
        
    return 0;
}
