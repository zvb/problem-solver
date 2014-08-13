#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = M_PI;

double a, r;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%lf%lf", &a, &r);
    if (r * sqrt(2) >= a ) printf("%.3lf\n", a*a);
    else if (2*r <= a) printf("%.3lf\n", pi*r*r);
    else {
        double x = sqrt(r*r - (a*a)/4);
        double th = 2*asin(x/r);
        double hat = (th-sin(th))*r*r/2;
        double res = pi*r*r - 4*hat;
        printf("%.3lf\n", res);
    }
    
    return 0;
}