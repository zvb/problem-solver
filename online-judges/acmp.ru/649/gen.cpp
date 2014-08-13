#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    clock_t ct = (clock() * time(0));
    srand(ct);
    cerr << ct << endl;
    int n = 10, k = rand()%9 + 1;
    printf("%d %d\n", n, k);
    for (int i = 0 ; i < n ; i ++)
        putchar(rand() % 5 + 'a');
    puts("");
    return 0;
}