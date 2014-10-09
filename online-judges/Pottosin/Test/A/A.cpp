#include <cstdio>
#include <cstdlib>
using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long n;
    scanf("%lld", &n);
    if ( n <= 0 ) {
        long long m = -n;
        printf("%lld\n", 1-m*(m+1)/2);
    } else {
        printf("%lld\n", n*(n+1)/2);
    }
    return 0;
}