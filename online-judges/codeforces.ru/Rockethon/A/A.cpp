#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 100;




int n, m;
int k1, k2;



int main() {
    
    scanf("%d%d", &n, &m);
    scanf("%d%d", &k1, &k2);
    
    if (n <= m)
        puts("Second");
    else
        puts("First");
    
    return 0;
}