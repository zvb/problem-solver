#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = 3.1415926535, g = 10.0;


double v, a, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%lf%lf%lf", &v, &a, &k);
    a = pi * (a / 180);
    printf("%.2lf\n", v*v*sin(2*a)/g*(k)/(k-1));
    
    return 0;
}