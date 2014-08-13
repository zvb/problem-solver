#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 555;
int n, m;

int x[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1  ; i <= n; i++)
        scanf("%d", &x[i]);
    double best = 0.0;
    for (int i = 0 ; i < m ; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        double rel = (x[a] + x[b] + 0.0) / c;
        if (rel > best)
            best = rel;
    }
    printf("%.12lf\n", best);
    
    
    return 0;
}