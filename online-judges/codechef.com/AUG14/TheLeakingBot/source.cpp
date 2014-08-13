#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool ok(int x, int y) {
    if (y % 2 == 0) {
        int k = y / 2;
        if (k == 0) {if (0 <= x && x <= 1) return 1;}
        else if (k < 0) {
            k = -k;
            if (-2*k <= x && x <= 2*k + 1) return 1;
        } else {
            if (-2*k <= x && x <= 2*k - 1) return 1;
        }
    }
    if ((x % 2 + 2)%2 == 1) {
        if (x > 0) {
            int k = (x + 1)/2;
            if (2-2*k <= y && y <= 2*k) return 1;
        }
    } else {
        if (x < 0) {
            int k = -x / 2;
            if (-2*k <= y && y <= 2*k) return 1;
        }
    }
    return 0;
}

int main() {
/*
    for (int y = 10 ; y >= -10 ; y --) {
        for (int x = -10 ; x <= 10 ; x ++)
            printf("%d ", ok(x, y));
        puts("");
    }
*/

    int t;
    scanf("%d", &t);
    while (t --) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (ok(x, y)) puts("YES");
        else puts("NO");
    }

    return 0;
}