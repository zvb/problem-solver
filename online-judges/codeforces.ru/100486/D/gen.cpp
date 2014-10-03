#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    srand( clock() * (time(0) % 7 + 1) );
    int t = 5;
    while (t --) {
        int n = 5, m = 7;
        printf("%d %d\n", n, m);
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                printf("%d ", rand()%7);
            }
            puts("");
        }
    }
    puts("0 0");
    return 0;
}