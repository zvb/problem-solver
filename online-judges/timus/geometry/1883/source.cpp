#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 1005
using namespace std;

const long long inf = (long long)1e9;

struct point {
    long long x, y;
    point operator-(point& o) {
        point ret = {x - o.x, y - o.y};
        return ret;
    }
    point operator+(point& o) {
        point ret = {x + o.x, y + o.y};
        return ret;
    }
    long long operator*(const point& o) const { return x*o.y - y*o.x; }
    long long operator^(const point& o) const { return x*o.x + y*o.y; }
    bool operator<(const point& o) const { return x < o.x || (x == o.x && y < o.y); }
};
bool BY_SLOPE(const point& l, const point& r) {
    long long X = l * r;
    if (X > 0) return 1;
    if (X < 0) return 0;
    return (l^l) < (r^r);
}
// graham scan

int n, k;
void convex_hull(point P[], int N, vector<point>& hull) {
    hull.clear();
    sort(P, P + N);
    point O = P[0];
    for (int i = 1 ; i < N ; i ++)
        P[i] = P[i] - P[0];
    P[0] = P[0] - P[0];
    sort(P + 1, P + N, BY_SLOPE);
    for (int i = 0; i <= k + 1 ; i ++) {
        if (i < 2) {
            hull.push_back(P[i]);
            continue;
        }
        int sz = hull.size();
        while (sz >= 2 &&
               (P[i] - hull[sz - 1]) * (hull[sz - 1] - hull[sz - 2]) >= 0)
        {
            hull.pop_back();
            sz --;
        }
        hull.push_back(P[i]);
    }
    for (int i = 0 ; i < hull.size() ; i++)
        hull[i] = O + hull[i];
}


point p[MAXN];
vector<point> hull;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++)
        cin >> p[i].x >> p[i].y;
    p[n].x = -inf; p[n].y = -inf+1;
    p[n+1].x = -inf+1; p[n+1].y = -inf;
    convex_hull(p, n + 2, hull);
    int h = hull.size();
    cout << h << '\n';
    for (int i = 0 ; i < h ; i ++) {
        cout << hull[i].x << ' ' << hull[i].y << '\n';
    }
    return 0;
}
