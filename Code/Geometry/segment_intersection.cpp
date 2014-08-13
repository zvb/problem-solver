#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>


using namespace std;
// ----------------------BEGIN
const double inf = 1e100, eps = 1e-12;

struct point {
	double x, y;
    point() {}
    point(double _x, double _y): x(_x), y(_y) {}
	double r() { // returns absolute value of the vector
		return sqrt(x*x+y*y);
	}
    double arg() { // returns argument of the vector [-pi, pi)
        if (r() < eps) return 0.0;
        return atan2(y, x);
    }
	bool operator<(const point& r) const {
		if (x < r.x) return 1;
		if (x > r.x) return 0;
		return y < r.y;
	}
	point operator-(point& r) {
		return point(x-r.x, y-r.y);
	}
    point operator+(point& r) {
		return point(x+r.x, y+r.y);
	}
	double slope() {
		if (x == 0.0 && y == 0.0) return -inf;
		if (x == 0.0) return inf;
		return y/x;
	}
	double operator*(const point& r) { // cross product
		return x*r.y - y*r.x;
	}
    double operator^(const point& r) { // dot product
        return x*r.x + y*r.y;
    }
    point rotate(double alpha) { // returns vector = this vector, rotated CCW by alpha
        double _r = r(), theta = arg();
        return point(_r*cos(theta + alpha), _r*sin(theta + alpha));
    }
    void normalize() {
        double _r = r();
        assert(_r > eps);
        x /= _r;
        y /= _r;
    }
};


bool intersect(point s1[2], point s2[2]) { // returns 1 if s1 and s2 intersect
    if (max(s1[0].x, s1[1].x) < min(s2[0].x, s2[1].x)) return 0;
    if (max(s1[0].y, s1[1].y) < min(s2[0].y, s2[1].y)) return 0;
    if (max(s2[0].x, s2[1].x) < min(s1[0].x, s1[1].x)) return 0;
    if (max(s2[0].y, s2[1].y) < min(s1[0].y, s1[1].y)) return 0;
    if ( ((s2[0] - s1[0])*(s1[1] - s1[0])) * ((s1[1] - s1[0])*(s2[1] - s1[0])) < 0)
        return 0;
    if ( ((s1[0] - s2[0])*(s2[1] - s2[0])) * ((s2[1] - s2[0])*(s1[1] - s2[0])) < 0)
        return 0;
    return 1;
}
// ----------------------END
point S1[2], S2[2];
int main() {
    for (int i = 0 ; i < 2 ; i ++)
        scanf("%lf%lf", &S1[i].x, &S1[i].y);
    for (int i = 0 ; i < 2 ; i ++)
        scanf("%lf%lf", &S2[i].x, &S2[i].y);
    if (intersect(S1, S2))
        puts("Yes");
    else
        puts("No");
    return 0;
}

    
