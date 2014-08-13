#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;
const double inf = 1e100, pi = M_PI, eps = 1e-7;

struct point {
    double x, y;
    point() {}
    point(double _x, double _y): x(_x), y(_y) {}
    point operator-(point& o) { return point(x - o.x, y - o.y); }
    point operator+(point& o) { return point(x + o.x, y + o.y); }
    double operator*(const point& o) const { return x*o.y - y*o.x; }
    double operator^(const point& o) const { return x*o.x + y*o.y; }
    double r() { return sqrt(x*x+y*y); }
    double arg() { return (fabs(y) < eps && fabs(x) < eps) ? 0.0 : atan2(y, x);}
    point operator%(double ang) {
        double R = r(), theta = arg() + ang;
        return point(R*cos(theta), R*sin(theta));
    }
    point normzd() {
        double R = r();
        return point(x/R, y/R);
    }
    void print() {
        printf("%.12lf %.12lf\n", x, y);
    }
};


point a[10];
bool check(point a, point b, point c) {
    double x = (b - a).r(), y = (c - b).r(), z = (a - c).r();
    if ( fabs(x - y) < eps && fabs(y - z) < eps) return 1;
    return 0;
    
}

int main() {
    //ios_base::sync_with_stdio(0);
    
    for (int i = 1 ; i <= 3 ; i ++)
        scanf("%lf%lf", &a[i].x, &a[i].y);
    a[0] = point(0, 0);
    for (int i = 1 ; i <= 3 ; i ++) {
        a[0].x += a[i].x / 3;
        a[0].y += a[i].y / 3;
    }
    for (int i = 1 ; i <= 3 ; i ++) {
        a[i + 3] = (a[i] - a[0])%(pi/3) + a[0];
        a[i + 6] = (a[i] - a[0]).normzd() ;
        a[i + 6].x *= 1.01; a[i+6].y *= 1.01;
        a[i + 6] = a[i + 6] + a[0];
    }
    a[8] = (a[7] - a[0])%(pi/3) + a[0];
    
    int ans = 0;
    for (int i = 0 ; i < 9 ; i ++) {
        for (int j = i + 1 ; j < 9 ; j ++) {
            if ( (a[i] - a[j]).r() < 1.0) {
                //cout << "ERROR" << i << ' ' << j << endl;
                //cout << (a[i] - a[j]).r() << endl;
                assert(false);
            }
            
        }
    }
    for (int i = 0 ; i < 9 ; i ++) {
        for (int j = i + 1 ; j < 9 ; j ++) {
            for (int k = j + 1 ; k < 9 ; k ++) {
                if (check(a[i], a[j], a[k])) {
                    ans ++;
                    //cout << "(" << i << ' ' << j << ' ' << k << ")\n";
                }
            }
        }
    }
    //cout << ans << endl;
     /*
    printf("%.12lf\n", (a[0] - a[7]).r());
    printf("%.12lf\n", (a[0] - a[8]).r());
    printf("%.12lf\n", (a[8] - a[7]).r());
     */
    assert(ans >= 9);
    a[0].print();
    a[7].print();
    a[8].print();
    for (int i = 4 ; i <= 6 ; i ++)
        a[i].print();
    
    
    return 0;
}