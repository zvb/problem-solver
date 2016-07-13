#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>


using namespace std;

#define filename "kolmogorov"

const int N = (int)1e5 + 100;

int n, m;

map<int, double> ne[N];
vector<int> g[N];
double dist[N];
priority_queue<pair<double, int> > q;

int main() {
    //freopen(filename ".in", "r", stdin);
    //freopen(filename ".out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0 ; i < m ; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        //ne[a][b] = 1e100;
        //ne[b][a] = 1e100;
    }
    for (int i = 0 ; i <= n ; i ++)
        dist[i] = 1e100;
    dist[n] = 0.0;
    q.push(make_pair(0, n));
    while (!q.empty() ) {
        int cur = q.top().second;
        q.pop();
        double d = dist[cur];
        
        
        if (d > -q.top().first)
            continue;
        
        for (int i = 0 ; i < g[cur].size(); i ++) {
            int to = g[cur][i];
            ne[to][cur] = d;
            vector<double> v;
            for (map<int, double>::iterator it = ne[to].begin(); it != ne[to].end(); it++) {
                v.push_back(it->second);
            }
            sort(v.begin(), v.end());
            double curS = 0.0, best = 1e100;
            for (int j = 0 ; j < v.size(); j ++) {
                curS += v[j];
                best = min(best, curS / (j + 1) + 1.0 * m / (j + 1));
            }
            if (best < dist[to]) {
                dist[to] = best;
                q.push(make_pair(-best, to));
                //cout << "relaxed " << to << " with " << best << " from " << cur << endl;
            }
        }
    }
    printf("%.10lf\n", dist[1]);
    
    
    return 0;
}