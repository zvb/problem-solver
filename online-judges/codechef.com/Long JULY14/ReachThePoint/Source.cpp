#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d ", &T);
    while (T --) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0 && y < 0) {
            x = -x;
            y = -y;
        } else if (x < 0)
            x = -x;
        else if (y < 0)
            y = -y;
        long long ans = 0;
        int mx = min(x, y);
        x -= mx; y -= mx;
        ans += 2*mx;
        mx = x + y;
        if (mx & 1)
            ans += 2*mx - 1;
        else
            ans += 2*mx;
        if (x > 0 && mx % 2 == 1)
            ans += 2;
        printf("%lld\n", ans);
    }
    return 0;
}