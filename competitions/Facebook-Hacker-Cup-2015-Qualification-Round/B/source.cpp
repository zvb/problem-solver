#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n;
int P, C, F;
int p[25], c[25], f[25];

int main() {

    scanf("%d\n", &t);
    for (int tt = 1 ; tt <= t ; tt ++) {
        scanf("%d%d%d", &P, &C, &F);
        scanf("%d", &n);
        for (int i = 0 ; i < n ; i ++) {
            scanf("%d%d%d", &p[i], &c[i], &f[i]);
        }
        bool ok = 0;
        for (int mask = 0 ; mask < (1 << n) ; mask ++) {
            int proteins = 0, carbonates = 0, fats = 0;
            for (int i = 0 ; i < n ;  i++) {
                if (mask & (1 << i)) {
                    proteins += p[i];
                    carbonates += c[i];
                    fats += f[i];
                }
            }
            if (proteins == P && carbonates == C && fats == F) {
                printf("Case #%d: yes\n", tt);
                ok = 1;
            }
        }
        if (!ok)
            printf("Case #%d: no\n", tt);
    }
    
    return 0;
}
