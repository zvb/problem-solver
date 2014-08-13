#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define N 100100
using namespace std;
struct edge {
    int to, cost;
};
vector<edge> g[N];
priority_queue<pair<int, int> > q;

int n, m, d[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0 ; i < m ; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge e1 = {b, 0};
        edge e2 = {a, 1};
        if (a != b) {
            g[a].push_back(e1);
            g[b].push_back(e2);
        }
    }
    for (int i = 1 ; i <= n ; i ++)
        d[i] = 1 << 30;
    d[1] = 0;
    q.push(make_pair(-d[1], 1));
    while (!q.empty()) {
        int c = q.top().second, dist = -q.top().first;
        q.pop();
        if (dist != d[c]) continue;
        for (int i = 0 ; i < g[c].size() ; i ++) {
            int to = g[c][i].to, cost = g[c][i].cost;
            if (d[to] > d[c] + cost) {
                d[to] = d[c] + cost;
                q.push(make_pair(-d[to], to));
            }
        }
    }
    if (d[n] >= (1 << 30)) {
        puts("-1");
    } else {
        printf("%d\n", d[n]);
    }
    return 0;
}