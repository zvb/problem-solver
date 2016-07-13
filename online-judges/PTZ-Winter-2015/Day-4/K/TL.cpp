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

struct pr {
    double d;
    int v;
    pr() {
    }
    pr(double _d, int _v): d(_d), v(_v) {}
};


struct cmp {
    bool operator () (const pr& a, const pr& b) {
        pr aa =(pr)a, bb = (pr)b;
        return aa.d >= bb.d;
    }
};

priority_queue< pr, std::vector<pr>, cmp > q;


int main() {
    freopen(filename ".in", "r", stdin);
    freopen(filename ".out", "w", stdout);
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
    q.push(pr(0, n));
    while (!q.empty() ) {
        int cur = q.top().v;
        double di = q.top().d;
        q.pop();
        if (dist[cur] < di)
            continue;

        
        //cout << "cur = " << cur << " with " << dist[cur] << endl;
        
        vector<double> v;
        for (int i = 0 ; i < g[cur].size(); i ++) {
            int to = g[cur][i];
            if (dist[to] < dist[cur]) {
                v.push_back(dist[to]);
            }
        }
        sort(v.begin(), v.end());
        double best = 1e100, curS = 0.0;
        for (int j = 0; j < v.size(); j ++) {
            curS += v[j];
            best = min(best, curS / (j + 1) + 1.0*m / (j + 1));
        }
        bool flag = false;
        if (best < dist[cur]) {
            dist[cur] = best;
            flag = true;
        }
        //cout << "cur = " << cur << " best = " << best << " dist[cur] = " << dist[cur] << endl;
        
        
        for (int i = 0 ; i < g[cur].size(); i ++) {
            int to = g[cur][i];
            if (dist[to] > dist[cur]) {
                dist[to] = dist[cur] + m;
                q.push(pr(dist[to], to));
                //cout << "Relaxed " << to << " from " << cur << " with " << dist[to] << endl;
                flag = 1;
            }
        }
        /*if (flag && f2)
            q.push(make_pair(-dist[cur], cur));
        for (int i = 0 ; i < g[cur].size(); i ++) {
            int to = g[cur][i];
            if (dist[to] < dist[cur]) {
                v.push_back(dist[to]);
            }
        }
        sort(v.begin(), v.end());
        best = 1e100, curS = 0.0;
        for (int j = 0; j < v.size(); j ++) {
            curS += v[j];
            best = min(best, curS / (j + 1) + 1.0*m / (j + 1));
        }
        if (best < dist[cur]) {
            dist[cur] = best;
            d = best;
            flag = true;
        }*/
        
    }
    printf("%.12lf\n", dist[1]);
    
    
    return 0;
}