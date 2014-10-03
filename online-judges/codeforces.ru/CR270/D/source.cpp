#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int N = (int)2e3 + 100;

int n;

long long d[N][N], u[N];
long long hh[N];
vector<pair<int, int> > g[N];

bool bad = 0;

void dfs(int v, long long h = 0, int p = -1) {
    if (bad) return;
    u[v] = 1;
    hh[v] = h;
    for (int i = 0 ; i < g[v].size() ; i ++) {
        int to = g[v][i].second;
        long long cost = g[v][i].first;
        if (u[to]) {
            
        } else {
            if ( p == -1)
                dfs(to, h + cost, v);
            else {
                if (d[p][to] + d[p][v] == d[v][to])
                    ;
                else if (d[p][to] == d[p][v] + d[v][to])
                    dfs(to, h + cost, v);
                else {
                    bad = 1;
                    return;
                }
            }
        }
    }
}


int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            scanf("%d", &d[i][j]);
            if (i == j) {
                if (d[i][j] != 0)
                    bad = 1;
            } else {
                if (d[i][j] == 0)
                    bad = 1;
            }
        }
    }
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            if (d[i][j] != d[j][i])
                bad = 1;
        }
    }
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            if (i != j) {
                g[i].push_back(make_pair(d[i][j], j));
            }
        }
    }
    for (int i = 0 ; i < n ; i ++)
        sort(g[i].begin(), g[i].end());
    //cout << bad << endl;
    if (!bad)
        dfs((rand()%n + n)%n);
    
    if (bad)
        puts("NO");
    else
        puts("YES");

    
    return 0;
}