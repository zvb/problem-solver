#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double inf = 1e6, eps = 1e-9, pi = M_PI;

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
};
point a, b;
double f(double x) {
    point X(x, 0);
    return acos( ((a-X)^(b-X))/((a-X).r() * (b-X).r()) );
}
double check(double lo, double hi) {
    
    while (hi - lo > eps) {
        //cout << "while :" << lo << ' ' << hi << '\n';
        double m1 = lo + (hi - lo)/3, m2 = lo + 2*(hi - lo)/3;
        if (f(m1) < f(m2))
            lo = m1;
        else
            hi = m2;
    }
    return f(lo);
}


int main() {
    scanf("%lf%lf", &a.x, &a.y);
    scanf("%lf%lf", &b.x, &b.y);
    if (a.y * b.y < 0 + eps) {
        printf("%.6lf\n", pi);
        return 0;
    }
    double best = 0;
    if ( fabs(a.y - b.y) < eps ) {
        best = max(best, check(-1000, 1000));
    } else {
        double p, q, r;
        p = -(b - a).y; // != 0
        q = (b - a).x;
        r = a*(b - a);
        double lim = -r/p;
        //cout << "lim = " << lim << endl;
        best = max(best, check(-inf, lim));
        //cout << "first" << endl;
        best = max(best, check(lim, inf));
    }
    printf("%.6lf\n", best);
    return 0;
}