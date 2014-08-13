#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const double pi = M_PI;

struct point {
    double x, y;
    point() {}
    point(double _x, double _y): x(_x), y(_y) {}
    point operator-(const point& o) const { return point(x - o.x, y - o.y); }
    point operator+(const point& o) const { return point(x + o.x, y + o.y); }
    double operator*(const point& o) const { return x*o.y - y*o.x; }
    point operator*(double scalar) { return point(x*scalar, y*scalar); }
    double operator^(const point& o) const { return x*o.x + y*o.y; }
    double r() { return sqrt(x*x+y*y); }
    double arg() { return (fabs(y) < 1e-9 && fabs(x) < 1e-9) ? 0.0 : atan2(y, x);}
    point operator%(double ang) { // rotate by ang radians CCW
        double R = r(), theta = arg() + ang;
        return point(R*cos(theta), R*sin(theta));
    }
    point normalized(double norm = 1.0) {              // get normalized
        double R = r();
        return point(x*norm/R, y*norm/R);
    }
    void print() { printf("%.9lf %.9lf\n", x, y); }
};

point p[5];
double base;

int main() {
    for (int i = 0 ; i < 3 ; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    
    base = (p[0] - p[1]).r();
    p[3] = p[0];
    for (int i = 0 ; i < 3 ; i ++) {
        for (int j = i + 1 ; j < 3; j ++) {
            int k = 3 - i - j;
            if ( ( (p[i] - p[k])^(p[j] - p[k]) ) < base*1e-7 +
                (p[i] - p[k]).r() * (p[j] - p[k]).r() * cos(2*pi/3) ) {
                p[k].print();
                return 0;
            }
        }
    }
    if ( (p[1] - p[0]) * (p[2] - p[0]) < base * 1e-7 ) swap(p[1], p[2]);
    point a02 = p[2] - p[0];
    point o1 = p[0] + (a02%(pi/6)).normzd(a02.r()/sqrt(3));
    point a01 = p[1] - p[0];
    point o2 = p[0] + (a01%(-pi/6)).normzd(a01.r()/sqrt(3));
    double th = acos( ((p[0] - o1)^(o2 - o1))/((p[0] - o1).r() * (o2 - o1).r()) );
    point o = o1 + (p[0] - o1)%(2*th);
    o.print();
    return 0;
}

