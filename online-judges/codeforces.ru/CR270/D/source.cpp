#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int N = (int)2e3 + 10;



struct Dsu {
    int *id, sz;
    Dsu() {}
    Dsu (int n) {
        id = new int[n];
        for (int i = 0 ; i < n ; i++)
            id[i] = i;
        sz = n;
    }
    int root(int x) {
        while (x != id[x]) {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }
    void unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y)
            return;
        sz --;
        if (rand() & 1)
            id[x] = y;
        else
            id[y] = x;
    }
};

int n;

int d[N][N];
struct edge {
    int cost, from, to;
    bool operator<(const edge& o) const {
        return cost < o.cost;
    }
};

edge E[N*N]; int en = 0;

void die(int ans) {
    if (ans) cout << "YES\n";
    else cout << "NO\n";
    exit(0);
}

vector< pair<int, int> > g[N];
int bad = 0;

void dfs(int root, int v, int p = -1, long long dist = 0) {
    if (bad) return;
    if (d[root][v] != dist) {
        bad = 1;
        return;
    }
    for (int j = 0; j < g[v].size() ; j ++) {
        int to = g[v][j].first, cost = g[v][j].second;
        if (to != p) {
            dfs(root, to, v, dist + cost);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++)
            cin >> d[i][j];
    }
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            if (i == j) {
                if (d[i][j] != 0)
                    die(0);
            }
            else {
                if (d[i][j] <= 0)
                    die(0);
                if (d[i][j] != d[j][i])
                    die(0);
            }
        }
    }
    for (int i = 0 ; i < n ; i ++) {
        for (int j = i + 1 ; j < n ; j ++) {
            E[en].cost = d[i][j];
            E[en].from = i;
            E[en].to = j;
            en ++;
        }
    }
    sort(E, E + en);
    Dsu dsu(n);
    for (int j = 0 ; j < en ; j ++) {
        int cost = E[j].cost, from = E[j].from, to = E[j].to;
        if (dsu.root(from) == dsu.root(to))
            continue;
        else {
            dsu.unite(from, to);
            g[from].push_back(make_pair(to, cost));
            g[to].push_back(make_pair(from, cost));
        }
    }
    for (int i = 0 ; i < n ; i ++) {
        dfs(i, i);
    }
    if (bad) die(0);
    die(1);
    
    
    return 0;
}