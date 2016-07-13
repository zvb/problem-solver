#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int lim = (int)1e7;

int main() {
    srand(time(0) + clock());
    int t = 100;
    printf("%d\n", t);
    while (t --) {
        long long n = rand() * rand() * rand();
        n = ((n%lim) + lim)%lim;
        cout << n << '\n' ;
    }
    return 0;
}