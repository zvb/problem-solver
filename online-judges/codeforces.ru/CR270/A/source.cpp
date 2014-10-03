#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000100;

int sieve[N], n;

int main() {
    sieve[1] = 1;
    for (int i = 2 ; i < N ; i ++ ) {
        if (!sieve[i])
            for (int j = 2*i ; j < N ; j += i)
                sieve[j] = 1;
    }
    scanf("%d", &n);
    for (int i = 2 ; i <= n / 2 ; i ++) {
        if (sieve[i] && sieve[n-i]) {
            printf("%d %d\n", i, n-i);
            return 0;
        }
    }
    
    return 0;
}