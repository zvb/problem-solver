#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

int main() {
    srand(time(0)*7 + clock());
    int n = 5;
    int q = 5;
    
    printf("%d\n", q);
    while (q --) {
        int l = rand() % n, r = rand()%n;
        if (l > r) swap(l, r);
        
        if (rand() & 1) {
            printf("1 %d %d\n", l, r);
        } else {
            int val = rand() % 10 + 1;
            printf("2 %d %d %d\n", l, r, val);
        }
    }
    return 0;
}