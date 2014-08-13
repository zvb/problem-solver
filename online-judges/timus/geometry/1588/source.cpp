#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <cmath>
#define N 305
using namespace std;

struct point {
    int x, y;
    point operator-(const point& o) const {
        point ret = {x - o.x, y - o.y};
        return ret;
    }
    int operator*(const point& o) const { return x*o.y - y*o.x; }
    int operator^(const point& o) const { return x*o.x + y*o.y; }
};

struct line {
    point a, b;
    int A, B, C;
    double _a, _b, _c;
    line() {}
    line(const point& __a, const point& __b) {
        a = __a, b = __b;
        point ab = b - a;
        A = ab.y; B = -ab.x;
        C = ab*a;
        double NN = sqrt(1.0*A*A + B*B);
        _a = A/NN;
        _b = B/NN;
        _c = C/NN;
        if (_a < 0) {
            _a = -_a;
            _b = -_b;
            _c = -_c;
        }
    }
    void update(const point& o) {
        point oa = a - o, ob = b - o;
        if (oa * ob != 0) return;
        if ( (oa^ob) < 0) return;
        if ( (oa^oa) < (ob^ob) ) a = o;
        else b = o;
    }
    bool operator<(const line& o) const {
        if (_a < o._a) return 1;
        else if (_a > o._a) return 0;
        else if (_b < o._b) return 1;
        else if (_b > o._b) return 0;
        return _c < o._c;
    }
    
};
line v[N*N];

bool check(const point& o, const point& a, const point& b) {
    point oa = a - o, ob = b - o;
    if ( (oa * ob) != 0) return 1;
    if ( (oa^ob) <= 0) return 1;
    return 0;
}

int vn = 0, n;

point p[N];
set<line> st;

int main() {

    scanf("%d", &n);
    for (int i = 0 ; i < n ; i ++)
        scanf("%d%d", &p[i].x, &p[i].y);
    double res = 0;
    for (int i = 0 ; i < n ; i ++) {
        for (int j = i + 1 ; j < n ; j ++) {
            bool ok = 1;
            for (int k = 0 ; k < n ; k ++) {
                if (i == k || j == k) continue;
                if (!check(p[k], p[i], p[j])) {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                res += sqrt((p[i]-p[j])^(p[i]-p[j]));
        }
    }

    printf("%0.0lf\n", res);

    return 0;
}