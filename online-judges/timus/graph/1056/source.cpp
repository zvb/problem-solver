#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int N = 10*1000 + 500, INF = 1 << 30;

vector<int> g[N];
int d[N], p[N];
int q[2*N], qh, qt, n;

int main() {
    scanf("%d", &n);
    for (int i = 2 ; i <= n ; i ++) {
        int pp;
        scanf("%d", &pp);
        g[pp].push_back(i);
        g[i].push_back(pp);
    }
    memset(d, -1, sizeof(d));
    memset(p, -1, sizeof(p));
    d[1] = 0;
    q[qh ++] = 1;
    
    int s = -1, mx = 0;
    
    while (qt < qh) {
        int cur = q[qt ++];
        for (int i = 0 ; i < g[cur].size() ; i++) {
            int to = g[cur][i];
            if (d[to] == -1) {
                d[to] = d[cur] + 1;
                q[qh ++] = to;
                
                if (d[to] > mx)
                    mx = d[to], s = to;
            }
        }
    }
    memset(d, -1, sizeof(d));
    d[s] = 0;
    qh = qt = 0;
    q[qh ++] = s;
    
    
    s = -1, mx = 0;
    while (qt < qh) {
        int cur = q[qt ++];
        for (int i = 0 ; i < g[cur].size() ; i++) {
            int to = g[cur][i];
            if (d[to] == -1) {
                d[to] = d[cur] + 1;
                q[qh ++] = to;
                p[to] = cur;
                if (d[to] > mx)
                    mx = d[to], s = to;
            }
        }
    }
    vector<int> ans;
    ans.push_back(s);
    while (p[s] != -1) {
        ans.push_back(p[s]);
        s = p[s];
    }
    if ( ans.size() & 1 ) {
        printf("%d\n", ans[ (ans.size()) / 2]);
    } else {
        int a = ans[ans.size() / 2 - 1], b = ans[ans.size() / 2];
        if (a > b) swap(a, b);
        printf("%d %d\n", a, b);
    }
    
    return 0;
}
