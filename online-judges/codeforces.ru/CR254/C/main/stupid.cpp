#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>

using namespace std;

int a[200000], w[200000];

int main() {
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1 ; i <= n ; i ++)
        a[i] = i;
    
    for (int i = 0 ; i < m ; i ++) {
        int t, l, r, x;
        scanf("%d", &t);
        if (t == 2) {
            scanf("%d%d", &l, &r);
            int sum = 0;
            for (int j = l ; j <= r; j ++)
                sum += w[j];
            printf("%d\n", sum);
        } else {
            scanf("%d%d%d", &l, &r, &x);
            for (int j = l ; j <= r; j ++) {
                w[j] += abs(a[j] - x);
                a[j] = x;
            }
        }
    }
    
   
    
    return 0;
}