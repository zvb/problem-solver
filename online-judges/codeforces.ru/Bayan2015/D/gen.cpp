#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;
int p[35];
int main() {
    int n = 100000;
    p[0] = 1;
    for (int i = 1 ; i <= 30 ; i++)
        p[i] = p[i-1] << 1;
    printf("%d\n", n);
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", p[30 - i%31]);
    }
    puts("");
    int q = 300;
    printf("%d\n", q);
    for (int i = 0 ; i < q; i ++) {
        printf("%d ", p[30 - i%31]);
    }
    puts("");
    
    return 0;
}
