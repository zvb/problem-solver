#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n, l, s;
    scanf("%lld%lld%lld", &n, &l, &s);
    if (l * l <= n * s * s)
        puts("YES");
    else
        puts("NO");
    return 0;
}