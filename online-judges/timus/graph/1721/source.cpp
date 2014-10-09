#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 2000;


namespace dinic {
    int n, s, t;
    struct edge {
        int a, b, c, f;
    };
    vector<int> g[N];
    vector<edge> E;
    void addEdge(int a, int b, int c) {
        edge e = {a, b, c, 0};
        edge er = {b, a, 0, 0};
        g[a].push_back(E.size());
        E.push_back(e);
        g[b].push_back(E.size());
        E.push_back(er);
    }
    
    int q[N], qh, qt, d[N], ptr[N];
    bool bfs() {
        qh = qt = 0;
        memset(d, -1, (n+5)*(sizeof(int)));
        q[qh ++] = s;
        d[s] = 0;
        while (d[t] == -1 && qt < qh) {
            int v = q[qt ++];
            //cout << "bfs() in " << v << endl;
            for (int i = 0 ; i < g[v].size(); i ++) {
                int id = g[v][i];
                if (E[id].f < E[id].c && d[E[id].b] == -1) {
                    d[E[id].b] = d[v] + 1;
                    q[qh ++] = E[id].b;
                }
            }
        }
        return d[t] != -1;
    }
    
    int dfs(int v, int F) {
        //cout << "dfs() : v=" << v << endl;
        if (v == t) return F;
        if (F == 0) return 0;
        for ( ; ptr[v] < g[v].size(); ptr[v] ++) {
            int id = g[v][ptr[v]];
            int to = E[id].b;
            if (d[to] == d[v] + 1 && E[id].f < E[id].c) {
                //cout << "dfs(): to=" << to << endl;
                int pushed = 0;
                if ( (pushed = dfs(to, min(F, E[id].c - E[id].f))) > 0) {
                    E[id].f += pushed;
                    E[id^1].f -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    
    int dinic() {
        //cout << "s, t = " << s << ' ' << t << endl;
        int F = 0;
        while (bfs()) {
            int f = 0;
            memset(ptr, 0, (n+5)*sizeof(int));
            while ( (f = dfs(s, 1 << 30)) > 0 )
                F += f;
        }
        return F;
    }
}

int n, r[N], spec[N];
string names[N];
vector<int> L, R;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i ++) {
        string s;
        cin >> names[i] >> s >> r[i];
        if (s == "anything")
            spec[i] = 3;
        else if (s == "statements")
            spec[i] = 2;
        else
            spec[i] = 1;
        int residue = r[i] % 4;
        if ( residue < 2 )
            L.push_back(i);
        else
            R.push_back(i);
    }
    dinic::n = n + 2;
    dinic::s = 0;
    dinic::t = n + 1;
    for (int i = 0 ; i < L.size() ; i++) {
        dinic::addEdge(dinic::s, L[i], 1);
    }
    for (int i = 0 ; i < R.size() ; i++) {
        dinic::addEdge(R[i], dinic::t, 1);
    }
    for (int i = 0 ; i < L.size() ; i ++) {
        for (int j = 0 ; j < R.size() ; j ++) {
            if ( abs(r[L[i]] - r[R[j]]) == 2 && (spec[L[i]] | spec[R[j]]) == 3 ) {
                dinic::addEdge(L[i], R[j], 1);
            }
        }
    }
    cout << dinic::dinic() << '\n';
    for (int i = 0 ; i < L.size() ; i ++) {
        for (int j = 0 ; j < dinic::g[L[i]].size() ; j ++) {
            int id = dinic::g[L[i]][j];
            if (dinic::E[id].f == 1) {
                int a = dinic::E[id].a, b = dinic::E[id].b;
                if ( !(spec[a] & 2) ) swap(a, b);
                else if ( !(spec[b] & 1) ) swap(a, b);
                cout << names[a] << ' ' << names[b] << '\n';
            }
        }
    }
    return 0;
}
