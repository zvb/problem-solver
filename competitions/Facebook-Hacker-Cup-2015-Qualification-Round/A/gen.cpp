#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

char str[20], s[20];

int get109() {
    int t = (rand() * rand() * rand()) % 1000000000;
    if (t < 0) t += 1000000000;
    return t;
}

int main() {
    srand(time(0) * 7 + clock());
    int t = 100, n;
    printf("%d\n", t);
    for (int tt = 1 ; tt <= t ; tt ++) {
        printf("%d\n", get109());
    }
    
    return 0;
}
