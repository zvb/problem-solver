#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double inf = 1e9, eps = 1e-8, pi = M_PI;

struct point {
    double x, y;
    point() {}
    point(double _x, double _y): x(_x), y(_y) {}
    point operator-(point& o) { return point(x - o.x, y - o.y); }
    point operator+(point& o) { return point(x + o.x, y + o.y); }
    double operator*(const point& o) const { return x*o.y - y*o.x; }
    point operator*(double scalar) { return point(x*scalar, y*scalar); }
    double operator^(const point& o) const { return x*o.x + y*o.y; }
    double r() { return sqrt(x*x+y*y); }
    double arg() { return (fabs(y) < eps && fabs(x) < eps) ? 0.0 : atan2(y, x);}
    point operator%(double ang) { // rotate by ang radians CCW
        double R = r(), theta = arg() + ang;
        return point(R*cos(theta), R*sin(theta));
    }
    point normalized(double norm = 1.0) {              // get normalized
        double R = r();
        return point(x*norm/R, y*norm/R);
    }
    void print() {
        printf("%.12lf %.12lf\n", x, y);
    }
    double rr() {
        return x*x+y*y;
    }
};
point a, b;
double r, d;
double f(double th) {
    return 4 * (r*r - a.rr()*(1 + cos(2*th))/2);
}
point t[4];
bool _try(double th) {
    if (th > eps)
        t[0] = a.normalized(r)%(th + pi/4);
    else
        t[0] = a.normalized(r)%(th - pi/4);
    t[1] = t[0]%(pi/2);
    t[2] = point(-t[0].x, -t[0].y);
    t[3] = point(-t[1].x, -t[1].y);
    for (int i = 0 ; i < 4 ; i ++) {
        //cout << t[i].x << ' ' << t[i].y << endl;
        point bw = t[i] - b, be = t[(i+1)%4] - b;
        //cout << "cross & dot: " << fabs(bw * be) << ' ' << (be ^ bw) << endl;
        if ( fabs(bw * be) < .1 && (be ^ bw) < .1 )
            return 1;
    }
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%lf", &r); r *= 100;
        d = r*(sqrt(2));
        scanf("%lf%lf", &a.x, &a.y); a.x *= 100; a.y *= 100;
        scanf("%lf%lf", &b.x, &b.y); b.x *= 100; b.y *= 100;
        double y = 4*(r*r-a.rr());
        //cout << r*r << ' ' << a.rr() << endl;
        //cout << y << ' ' << d*d << endl;
        if (d*d < y - eps) {
            puts("NO");
            continue;
        }
        double lo = 0, hi = pi/2, m;
        while (hi - lo > 1e-15) {
            m = (hi + lo)/2;
            if (f(m) < d*d)
                lo = m;
            else
                hi = m;
        }
        //cout << "lo = " << lo << endl;
        if (_try(lo) || _try(-lo)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}