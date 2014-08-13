#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 111
using namespace std;

const double pi = M_PI;

struct point {
    double x, y;
    double operator*(const point& o) {
        return x * o.y - y * o.x;
    }
    double operator^(const point& o) {
        return x*o.x + y*o.y;
    }
    double r() {
        return sqrt(x*x+y*y);
    }
    point operator-(const point& o) {
        point res = {x - o.x, y - o.y};
        return res;
    }
};

int n;
double r;
point p[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%lf", &n, &r);
    for (int i = 0 ; i < n ; i ++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    double res = 0;
    for (int i = 0 ; i < n ; i++) {
        int prev = (i - 1 + n)%n, next = (i + 1)%n;
        point f = p[next] - p[i], s = p[prev] - p[i];
        res += f.r();
        //double angle = acos( (f^s) / (f.r() * s.r()) );
        //cout << angle / pi * 180 << endl;
        //res += (pi - angle)*r;
    }
    res += 2*r*pi;
    printf("%.2lf\n", res);
    
    return 0;
}