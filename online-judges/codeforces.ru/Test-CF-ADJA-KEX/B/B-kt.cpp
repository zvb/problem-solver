#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;


const int N = (int)1e5 + 100;

int n;

int a[N], b[N], c[N];


long long sa, sb, sc;

int main() {
    //freopen(filename ".in", "r", stdin);
    //freopen(filename ".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0 ; i < n ; i ++) {
        scanf("%d", &a[i]);
        sa += a[i];
    }
    for (int i = 0 ; i < n - 1 ; i ++) {
        scanf("%d", &b[i]);
        sb += b[i];
    }
    for (int i = 0 ; i < n - 2 ; i ++) {
        scanf("%d", &c[i]);
        sc += c[i];
    }
    cout << sa - sb << endl << sb - sc << endl;
    return 0;
}