#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = (int)2e5 + 100;

int gcd(int a, int b) {
    if (!a) return b;
    return gcd(b%a, a);
}

int logN[N];

struct SparseTable {
    int **d;
    SparseTable() {}
    SparseTable(int n, int *a) {
        int logn = logN[n] + 1;
        d = new int*[logn];
        for (int i = 0 ; i < logn ; i ++)
            d[i] = new int [n];
        for (int i = 0 ; i < n ; i ++)
            d[0][i] = a[i];
        for (int i = 1 ; i < logn ; i ++) {
            for (int j = 0 ; j + (1 << (i-1)) < n ; j ++) {
                d[i][j] = gcd(d[i-1][j], d[i-1][j + (1 << (i-1))]);
            }
        }
    }
    int get(int l, int r) {
        r ++;
        int lg = logN[r - l];
        return gcd(d[lg][l], d[lg][r-(1<<lg)]);
    }
};

int n, a[N];

int main() {
    for (int i = 1, j = 0; i < N ; i++) {
        if ( (1 << (j + 1)) <= i )
            j ++;
        logN[i] = j;
    }
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++)
        scanf("%d", &a[i]);
    SparseTable st(n, a);
    while (1) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", st.get(l, r));
    }
    
    
    return 0;
}
