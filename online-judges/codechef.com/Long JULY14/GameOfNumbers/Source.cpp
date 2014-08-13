#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 404;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

struct edge {
    int a, b, f, c;
};

vector<int> g[2*N*N];
vector<edge> E;
int s, t;


void add_edge(int _a, int _b, int _c) {
    edge e = {_a, _b, 0, _c};
    g[_a].push_back(E.size());
    E.push_back(e);
    e.c = 0; swap(e.a, e.b);
    g[_b].push_back(E.size());
    E.push_back(e);
}

int a[N], b[N], n;

int q[2*N*N], qh, qt, d[2*N*N], ptr[2*N*N];
bool bfs() {
    qh = qt = 0;
    q[qh ++] = s;
    for (int i = 0 ; i <= t ; i ++)
        d[i] = -1;
    d[s] = 0;
    while (qt < qh && d[t] == -1) {
        int cur = q[qt ++];
        for (int i = 0 ; i < g[cur].size() ; i ++) {
            int id = g[cur][i];
            if (d[E[id].b] == -1 && E[id].f < E[id].c) {
                d[E[id].b] = d[cur] + 1;
                q[qh ++] = E[id].b;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int flow) {
    if (flow == 0) return 0;
    if (v == t) return flow;
    for ( ; ptr[v] < g[v].size() ; ptr[v] ++) {
        int id = g[v][ptr[v]];
        if (d[E[id].b] != d[v] + 1)
            continue;
        int f = dfs(E[id].b, min(flow, E[id].c - E[id].f));
        if (f > 0) {
            E[id].f += f;
            E[id^1].f -= f;
            return f;
        }
    }
    return 0;
}

int dinic() {
    int F = 0;
    while (bfs()) {
        for (int i = 0 ; i <= t ; i ++)
            ptr[i] = 0;
        int pushed;
        while ( (pushed = dfs(s, 1 << 30)) > 0)
            F += pushed;
    }
    return F;
}

int L[N*N], R[N*N];

void solve() {
    E.clear();

    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i ++)
        scanf("%d", &a[i]);
    for (int i = 1 ; i <= n ; i ++)
        scanf("%d", &b[i]);
    vector<pair<int, pair<int, int> > > L, R;
    
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= n ; j ++) {
            if (a[i] < b[j] ) {
                int d = gcd(a[i], b[j]);
                if (d > 1)
                    L.push_back(make_pair(d, make_pair(a[i], b[j])));
            } else if (a[i] > b[j]) {
                int d = gcd(a[i], b[j]);
                //cout << "d=" << d << endl;
                if (d > 1)
                    R.push_back(make_pair(d, make_pair(a[i], b[j])));
            }
        }
    }
    /*
    for (int i = 0 ; i < L.size() ; i ++)
        cout << L[i].first << ' ' << L[i].second.first << ' ' << L[i].second.second << endl;
    cout << endl;
    for (int i = 0 ; i < L.size() ; i ++)
        cout << R[i].first << ' ' << R[i].second.first << ' ' << R[i].second.second << endl;
    */
    s = 0; t = L.size() + R.size() + 1;
    for (int i = 0 ; i <= t ; i ++)
        g[i].clear();
    for (int i = 0 ; i < L.size(); i ++) {
        for (int j = 0 ; j < R.size(); j ++) {
            int dl = L[i].first, dr = R[j].first;
            if (gcd(dl, dr) == 1)
                continue;
            //cout << "gcd = " << dl << ' ' << dr << endl;
            //cout << "adding " << L[i].second.first <<
            //' ' << L[i].second.second << " - " <<
            //R[j].second.first << ' ' << R[j].second.second << endl;
            add_edge(i + 1, L.size() + j + 1, 1);
        }
    }
    for (int i = 0 ; i < L.size() ; i ++)
        add_edge(s, i + 1, 1);
    for (int i = 0 ; i < R.size() ; i ++)
        add_edge(L.size() + i + 1, t, 1);
    
    printf("%d\n", dinic());
    
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --)
        solve();
    
    return 0;
}