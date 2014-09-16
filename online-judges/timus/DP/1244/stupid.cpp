#include <cstdio>
#include <cassert>

using namespace std;

int W, n, w[100];
int cnt[100];

int main() {
    scanf("%d%d", &W, &n);
    for (int i = 0 ; i < n ; i++)
        scanf("%d", &w[i]);
    int ans = -1;
    for (int mask = 0 ; mask < (1 << n) ; mask ++) {
        int c = 0;
        for (int i = 0 ; i < n ; i++) {
            if (mask & (1 << i)) {
                c += w[i];
            }
        }
        if (c == W) {
            if (ans == -1)
                ans = mask;
            else {
                puts("-1");
                return 0;
            }
        }
    }
    if (ans == -1) puts("0");
    else {
        //assert(false);
        for (int i = 0 ; i < n ; i ++) {
            if (!(ans & (1 << i)))
                printf("%d ", i + 1);
        }
        puts("");
    }
    
    return 0;
}