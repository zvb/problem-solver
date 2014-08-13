#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define sqr(x) ((x)*(x))

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
    double rr() { return x*x+y*y; }
    point normalized(double norm = 1.0) {              // get normalized
        double R = r();
        return point(x*norm/R, y*norm/R);
    }
    void print() { printf("%.9lf %.9lf\n", x, y); }
};

int z[3][3];
double d[3];
point a, b, c(0, 0);

double acos1(double x) {
    if (x > 1) x = 1;
    else if (x < -1) x = -1;
    return acos(x);
}
double sqrt1(double x) {
    if (x < 0) x = 0;
    return sqrt(x);
        
}

double base, r;
int main() {
    for (int i = 0 ; i < 3 ;i ++) {
        for (int j = 0 ; j < 3 ; j++)
            scanf("%d", &z[i][j]);
    }
    scanf("%lf", &r);
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = i + 1; j < 3 ;j ++) {
            int k = 3 - i - j;
            d[k] = 0.0;
            for (int l = 0 ; l < 3 ; l ++)
                d[k] += sqr(z[i][l] - z[j][l]);
            d[k] = sqrt1(d[k]);
            base += d[k];
            //cout << d[k] << endl;
        }
    }
    base /= 3;
    b = point(d[0], 0);
    a.x = ( sqr(d[0]) + sqr(d[1]) - sqr(d[2]) ) / (2*d[0]) ;
    a.y = sqrt1( sqr(d[1]) - sqr(a.x) );
    
    //a.print(); b.print(); c.print();
    
    point ac = c - a, ab = b - a;
    
    //cout << ac.r() << ' ' << ab.r() << ' ' << (b - c).r() << endl;
    
    point ch = a + ab*( (ac^ab)/(ab^ab) );
    
    
    if ( ((a - ch)^(b - ch)) < base * 1e-7 ) {
        if ( (ch - c).r() + base * 1e-7 > r) {
            printf("%.9lf\n", (a-b).r());
        } else {
            double res = sqrt1((c - b).rr() - r*r) + sqrt1( (c - a).rr() - r*r);
            double big = acos1( ((a - c)^(b - c))/((a - c).r()*(b-c).r()) );
            double left = acos1( r/(a-c).r() );
            double right = acos1( r/(b - c).r());
            res += r*(big - left - right);
            printf("%.9lf\n", res);
        }
    } else {
        printf("%.9lf\n", (a-b).r());
    }
    
    return 0;
}