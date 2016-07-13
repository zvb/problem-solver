#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;


const int N = (int)1e5 + 100;

int n, m, l;
vector<int> g[N];
vector<int> tin, tout;
int timer;
vector<int> up[N];
int depth[N];
int treeSize[N];


void dfs (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    treeSize[v] = 1;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p) {
            depth[to] = depth[v] + 1;
            dfs (to, v);
            treeSize[v] += treeSize[to];
        }
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}



int main() {
    scanf("%d", &n);
    for (int i = 1 ; i < n ; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --; b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    tin.resize (n),  tout.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs (0);
    
    
    scanf("%d", &m);
    
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --; b --;
        if ( a == b ) {
            printf("%d\n", n);
            continue;
        }
        if (upper(a, b)) {
            //cout << "here1\n";
            int diff = (depth[b] - depth[a]);
            if (diff % 2 == 1) {
                puts("0");
                continue;
            }
            diff /= 2;
            int k = diff - 1;
            int u = b;
            for (int i = l ; i >= 0; i --) {
                if (k & (1 << i)) {
                    u = up[u][i];
                }
            }
            int ans = -treeSize[u];
            u = up[u][0];
            ans += treeSize[u];
            printf("%d\n", ans);

        } else if (upper(b, a)) {
            swap(a, b);
            //cout << "here\n";
            int diff = (depth[b] - depth[a]);
            if (diff % 2 == 1) {
                puts("0");
                continue;
            }
            diff /= 2;
            int k = diff - 1;
            int u = b;
            for (int i = l ; i >= 0; i --) {
                if (k & (1 << i)) {
                    u = up[u][i];
                }
            }
            int ans = -treeSize[u];
            u = up[u][0];
            ans += treeSize[u];
            printf("%d\n", ans);
        } else {
            int u = lca(a, b);
            //cout << "here2\n";
            int diff = depth[b] + depth[a] - 2*depth[u];
            //cout << "diff = " << diff << " a, b = " << a << ',' << b << endl;
            //cout << "u = " << u << endl;
            if (diff % 2 == 1) {
                puts("0");
                continue;
            }

            if (depth[a] > depth[b])
                swap(a, b);
            if (depth[a] == depth[b]) {
                diff /= 2;
                int k = diff - 1;
                int pa = a;
                for (int i = l ; i >= 0 ; i--) {
                    if (k & (1 << i)) {
                        pa = up[pa][i];
                    }
                }
                int pb = b;
                for (int i = l ; i >= 0 ; i--) {
                    if (k & (1 << i)) {
                        pb = up[pb][i];
                    }
                }
                int ans = n - treeSize[pa] - treeSize[pb];
                printf("%d\n", ans);
            } else {
                diff /= 2;
                int k = diff - 1;
                int v = b;
                for (int i = l ; i >= 0 ; i--) {
                    if (k & (1 << i)) {
                        v = up[v][i];
                    }
                }
                int ans = -treeSize[v];
                v = up[v][0];
                ans += treeSize[v];
                printf("%d\n", ans);
            }
        }
    }
    
    return 0;
}