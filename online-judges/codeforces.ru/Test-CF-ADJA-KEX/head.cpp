#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

#define filename ""

const int N = (int)1e5 + 100;

int n, m;

map
vector<int> g[N];
double dist[N];
pair<int, int> q[N*4];


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
    
    
    return 0;
}