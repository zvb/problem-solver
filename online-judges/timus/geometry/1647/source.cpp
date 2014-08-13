#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-9;
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
    point normzd(double norm = 1.0) {              // get normalized
        double R = r();
        return point(x*norm/R, y*norm/R);
    }
    void print() {
        printf("%.12lf %.12lf\n", x, y);
    }
};
point h[3];

double x[3], y[3];
double a[3], r[3];
double s, p;
int main() {
    for (int i = 0 ; i < 3 ; i ++) {
        scanf("%lf%lf", &x[i], &y[i]);
        h[i] = point(x[i], y[i]);
    }
    for (int i = 0 ; i < 3; i ++) {
        for (int j = i + 1 ; j < 3 ; j++) {
            r[3 - i - j] = sqrt(sqr(x[i] - x[j]) + sqr(y[i]-y[j]));
        }
    }
    for (int i = 0 ; i < 3; i ++) {
        for (int j = i + 1 ; j < 3 ; j++) {
            a[3-i-j] = acos( (sqr(r[i]) + sqr(r[j]) - sqr(r[3-i-j]))/(2*r[i]*r[j]) );
        }
    }
    //s = .25*r[0]*r[1]*sin(a[2]);
    
    s = fabs( (h[1] - h[0])*(h[2] - h[0]) ) / 4;
    
    p = .5*(r[0] + r[1] + r[2]);
    for (int i = 0 ; i < 3; i ++) {
        for (int j = i + 1 ; j < 3 ; j++) {
            int k = 3 - i - j;
            double D = p*p - 2*r[i]*r[j];
            if (D < 0) continue;
            double x1 = .5*(p - sqrt(D)), x2 = .5*(p + sqrt(D));
            if (x1 < 0 || x2 < 0) continue;
            if (r[i] <= r[j] && x1 >= x2) swap(x1, x2);
            if (r[i] >= r[j] && x1 <= x2) swap(x1, x2);
            if (min(x1, x2) < min(r[i], r[j]) + eps && max(x1, x2) < max(r[i], r[j]) + eps) {
                point ans1 = (((h[j] - h[k]).normzd(x1))) + h[k];
                point ans2 = (((h[i] - h[k]).normzd(x2))) + h[k];
                
                double at = fabs((ans1 - h[k])*(ans2 - h[k])) / 2;
                double ar = 2*s - at;
                //printf("%.12lf %.12lf\n", at, ar);
                //printf("d area=%.12lf\n", fabs(at-ar));
                assert (fabs(at - ar) < eps);
                double pt = (ans1 - h[k]).r() + (ans2 - h[k]).r();
                double pr = 2*p - pt;
                assert (fabs(pt - pr) < eps);
                
                puts("YES");
                ans1.print();
                ans2.print();
                return 0;
            }
                
        }
    }
    puts("NO");
    return 0;
}