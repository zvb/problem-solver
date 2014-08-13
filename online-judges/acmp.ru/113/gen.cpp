#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int n = 5;
    printf("%d\n", n);
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0  ; j < n ; j ++)
            if ((rand() & 3) == 3)
                putchar('0');
            else putchar('1');
        puts("");
        
    }
    return 0;
}