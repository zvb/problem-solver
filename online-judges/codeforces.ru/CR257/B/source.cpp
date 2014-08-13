#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = (int)1e5 + 100;

struct edge {
    int to, w, train;
};

vector< edge > g[N];
long long d[N];
int p[N];
int by[N];



int n, m, k;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i= 0 ; i < m ; i ++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        edge e = {v, c, 0};
        g[u].push_back(e);
        e.to = u;
        g[v].push_back(e);
    }
    for (int i = 0 ; i < k ; i ++) {
        int to, c;
        scanf("%d%d", &to, &c);
        edge e = {to, c, 1};
        g[1].push_back(e);
    }
    priority_queue<pair<long long , int > > q;
    d[1] = 0;
    for (int i = 2 ; i <= n ; i ++)
        d[i] = 1ll << 60;
    q.push(make_pair(-d[1], 1));
    
    while (!q.empty()) {
        long long curd = -q.top().first;
        int curv = q.top().second;
        q.pop();
        if (d[curv] != curd) continue;
        for (int i = 0 ; i < g[curv].size(); i ++) {
            int to = g[curv][i].to, w = g[curv][i].w;
            if (d[curv] + w < d[to] || (d[curv] + w == d[to] && by[to] == 1
                                        && g[curv][i].train == 0)) {
                d[to] = d[curv] + w;
                p[to] = curv;
                by[to] = g[curv][i].train;
                q.push(make_pair(-d[to], to));
            }
        }
    }
    int res = 0;
    for (int i = 2 ; i <= n ; i ++) {
        if (p[i] == 1 && by[i] == 1)
            res ++;
    }
    cout << k - res << endl;
    
    

    
    return 0;
}