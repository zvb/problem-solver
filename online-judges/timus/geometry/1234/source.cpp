#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

const double pi = M_PI, eps = 1e-6;
double a[3], b[2];
double f(double a, double b, double th) {
    return a*cos(th) + b*sin(th);
}


bool _try(double a, double b, double p, double q) {
    //cout << a << ' ' << b << ' ' << p << ' ' << q << endl;
    if (a < p - eps)
        return 0;
    assert(a + eps > p);
    if (p < b - eps) {
        return 0;
    }
    double lo = 0, hi = pi/2, m1, m2;
    while (hi - lo > 1e-10) {
        m1 = lo + (hi - lo)/3, m2 = lo + 2*(hi - lo)/3;
        if (f(a, b, m1) < f(a, b, m2))
            lo = m1;
        else
            hi = m2;
    }
    hi = pi/2;
    while (hi - lo > eps) {
        m1 = (hi + lo)/2;
        if (a*cos(m1) + b*sin(m1) < p)
            hi = m1;
        else
            lo = m1;
    }
    double x = a*sin(lo) + b*cos(lo);
    if (x < q + eps) {
        //cout << a << ' ' << b << ' ' << p << ' ' << q << endl;
        //cout << x << ' ' << lo / pi * 180 << endl;
        return 1;
    }
    return 0;
}

int main() {
    //ios_base::sync_with_stdio(0);
    for (int i = 0 ; i < 3; i++) {
        scanf("%lf", &a[i]);
        //a[i] *= 10;
    }
    sort(a, a + 3);
    for (int i = 0 ; i < 2 ; i++) {
        scanf("%lf", &b[i]);
        //b[i] *= 10;
    }
    sort(b, b + 2);

    for (int i = 0 ; i < 3 ; i ++) {
        for (int j = i + 1; j < 3 ; j ++) {
            if (a[i] < b[0] + eps && a[j] < b[1] + eps) {
                puts("YES");
                return 0;
            }
            if (_try(a[j], a[i], b[1], b[0]) || _try(a[j], a[i], b[0], b[1])) {
                
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
   
    
    
    return 0;
}