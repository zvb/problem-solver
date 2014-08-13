#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = M_PI;

double p, q, r, s;

int main() {
    scanf("%lf%lf%lf%lf", &p, &q, &r, &s);
    if (p * q == r * s || p * r == q * s) {
        puts("Impossible.");
        return 0;
    }
    double A = 1.0 / (2*p*q) - 1.0 / (2*r*s);
    double B = (p*p + q*q) / (2*p*q) - (r*r+s*s)/(2*r*s);
    double X = B / A;
    if (X < 0) {
        puts("Impossible.");
        return 0;
    }
    double x = sqrt(X);
    double one = acos( (x*x + q*q - p*p)/(2*x*q) );
    double two = acos( (s*s + x*x - r*r)/(2*s*x) );
    if (one < two) {
        printf("Distance is %.lf km.\n", x * 1000);
    } else {
        puts("Impossible.");
    }
    
    return 0;
}