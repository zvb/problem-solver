#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;

const int N = 333, INF = 1 << 30;

int n, m;
vector<int> g[N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0 ; i < m ; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(-a);
    }
    int mx = -1;
    for (int r = 1 ; r <= n ; r ++) {
        priority_queue< pair<int, int> > q;
        std::vector<int> d(n+1, INF);
        q.push(make_pair(0, r));
        d[r] = 0;
        while (!q.empty()) {
            int v = q.top().second;
            int dist = -q.top().first;
            q.pop();
            if (dist != d[v])
                continue;
            for (int i = 0 ; i < g[v].size() ; i++) {
                int to = g[v][i];
                if (to > 0) {
                    if (d[to] > d[v]) {
                        d[to] = d[v] + 0;
                        q.push(make_pair(-d[to], to)); 
                    }
                } else {
                    to = -to;
                    if (d[to] > d[v] + 1) {
                        d[to] = d[v] + 1;
                        q.push(make_pair(-d[to], to));
                    }
                }
            }
        }
        for (int i = 1 ; i <= n ; i ++) {
            mx = max(mx, d[i]);
        }
    }
    printf("%d\n", mx);
    
    
    return 0;
}
