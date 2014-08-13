#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double inf = 1e9, eps = 1e-12, pi = M_PI;

struct point {
    int x, y;
    int operator*(point& o) {
        return x*o.y - y*o.x;
    }
    int operator^(const point& o) const {
        return x*o.x + y*o.y;
    }
    point operator-(const point& o) const {
        point ret = {x - o.x, y - o.y};
        return ret;
    }
    point rotate90() {
        point ret = {-y, x};
        return ret;
    }
};

int r;
bool can(point& a, point& b) {
    long long A2 = 1ll*(a*b)*(a*b);
    long long d2 = ((a-b))^((a-b));
    return d2*r*r == 2*A2;
}
point a, b;




int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &r);
        scanf("%d%d", &a.x, &a.y);
        scanf("%d%d", &b.x, &b.y);
        if ( 2*(a^a) < r*r || 2*(b^b) < r*r ) {
            puts("NO");
            continue;
        }
        bool ok = 0;
        for (int i = 0 ; i < 4 ; i++) {
            if (can(a, b)) {
                puts("YES");
                ok = 1;
                break;
            }
            a = a.rotate90();
        }
        if (!ok)
            puts("NO");
    }


    return 0;
}