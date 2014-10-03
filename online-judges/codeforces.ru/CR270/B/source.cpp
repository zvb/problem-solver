#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2002;

int n, k, f[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0 ; i < n ; i ++) {
        scanf("%d", &f[i]);
    }
    sort(f, f + n);
    int p = n - 1 ;
    int ans = 0;
    while ( p >= 0 ) {
        ans += 2*(f[p] - 1);
        p -= k;
    }
    printf("%d\n", ans);
    return 0;
}