#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

void getr() {
    int len = rand()%4 + 1;
    for (int i = 0 ; i < len ; i ++)
        putchar(rand()%2 + 'a');
}

int main() {
    srand((clock()%7 + 1) * clock());
    
    int n = 90;
    for (int i = 0 ; i < n ; i ++) {
        putchar(rand()%2 + 'a');
    }
    puts("");
    int q = 50;
    printf("%d\n", q);
    for (int i = 0 ; i < q ; i ++) {
        getr();
        putchar(' ');
        getr();
        puts("");
    }
    
    
    return 0;
}