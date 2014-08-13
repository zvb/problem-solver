#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#define K 50500

using namespace std;

int n, m, k;
vector<int> a[K];
int u[K];
int w[K];

int main() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1 ; i <= k ; i ++) {
        int q;
        scanf("%d", &q);
        for (int j = 0 ; j < q ; j ++) {
            int x;
            scanf("%d", &x);
            a[x].push_back(i);
        }
    }
    for (int i = 1 ; i <= n ; i ++) {
        int cur = 1;
        for (int j = 0 ; j < a[i].size(); j ++) {
            if (cur == m + 1) cur = 1;
            int st = a[i][j];
            if (!u[st]) {
                u[st] = 1;
                w[st] = cur;
                cur ++;
            }
        }
    }
    for (int i = 1 ; i <= k ; i ++)
        printf("%d\n", w[i]);
    return 0;
}