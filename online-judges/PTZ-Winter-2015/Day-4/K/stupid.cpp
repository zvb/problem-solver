#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <queue>


using namespace std;

#define filename "kolmogorov"

const int N = (int)1e5 + 100;

int n, m;

vector<int> g[N];

bool used[N];
double d[N];
double sum[N];
int cnt[N];

priority_queue< pair<double, int> > q;

int main() {
    //freopen(filename ".in", "r", stdin);
    //freopen(filename ".out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0 ; i < m ; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i ++)
        d[i] = 1e100;
    d[n] = 0;
    
    q.push(make_pair(-d[n], n));
    
    while (!q.empty()) {
        int cur = q.top().second;
        double curd = -q.top().first;
        q.pop();
        
        if (curd > d[cur])
            continue;
        if (curd == d[cur] && used[cur])
            continue;
        
        used[cur] = true;
        //cout << "cur = " << cur << " curd = " << curd << endl;
        
        for (int i = 0 ; i < g[cur].size(); i++) {
            int to = g[cur][i];
            if (d[to] > d[cur]) {
                //cout << "relaxing " << to << " from " << cur << endl;
                cnt[to] ++;
                sum[to] += d[cur];
                d[to] = (1.0*m + sum[to])/cnt[to];
                q.push(make_pair(-d[to], to));
            }
        }
        
    }
    printf("%.9lf\n", d[1]);
    
    
    
    
    return 0;
}