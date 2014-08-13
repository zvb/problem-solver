#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>

#define MAXN 20005
using namespace std;
const double inf = 1e100, pi = M_PI;
//===================BEGIN=====================
struct point {
    long long x, y;
    point operator-(point& o) {
        point ret = {x - o.x, y - o.y};
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
void convex_hull(point P[], int N, vector<point>& hull) {
    hull.clear();
    sort(P, P + N);
    for (int i = 1 ; i < N ; i ++)
        P[i] = P[i] - P[0];
    P[0] = P[0] - P[0];
    sort(P + 1, P + N, BY_SLOPE);
    for (int i = 0; i < N ; i ++) {
        if (i < 2) {
            hull.push_back(P[i]);
            //cout << "added " << P[i].x << ", " << P[i].y << endl;
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
}
//===================END=====================
int n, l;

point p[MAXN];

vector<point> v;

int main() {
    
    //scanf("%d%d", &n, &l);
    scanf("%d", &n);
    for (int i = 0 ; i < n ;i ++) {
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }
    convex_hull(p, n, v);
    //double res = 2*pi*l;
    double p = 0.0, s = 0.0;
	for (int i = 0 ; i < v.size() ; i ++) {
        point vv = v[i]-v[(i+1)%v.size()];
		p += sqrt(vv^vv);
		s += .5*(v[i]*v[(i+1)%v.size()]);
	}
    printf("%e\n%e\n", p, s);
    
    
    return 0;
}