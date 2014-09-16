#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;
const int N = 100100, INF = 1 << 30;

int a[N], b[N];

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int tc = 1;
    int n, m;
    while (true) {
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) break;
        
        for (int i = 0 ; i < n ; i ++)
            scanf("%d", &a[i]);
        for (int i = 0 ; i < m ; i ++)
            scanf("%d", &b[i]);
        sort(a, a + n);
        sort(b, b + m);
        
        int da = 0, db = 0;
        int aMax = a[0], aMin = a[0], bMin = b[0], bMax = b[0];
        int d = a[0];
        for (int i = 1 ; i < n ; i ++) {
            if (i == 1)
                da = a[i] - a[i-1];
            else
                da = gcd(da, a[i] - a[i-1]);
            d = gcd(d, a[i]);
            if (aMax < a[i]) aMax = a[i];
            if (aMin > a[i]) aMin = a[i];
        }
        for (int i = 1 ; i < m ; i ++) {
            if (i == 1)
                db = b[i] - b[i-1];
            else
                db = gcd(db, b[i] - b[i-1]);
            if (bMax < b[i]) bMax = b[i];
            if (bMin > b[i]) bMin = b[i];
        }
        int global = gcd(abs(a[0] - b[0]), db);
        //cout << "da, db = " << da << ',' << db << endl;
        
        for (int i = 1 ; i < n ; i ++) {
            global = gcd(global, gcd(abs(a[i] - b[0]), db));
        }
        //cout << global << endl;
        int bad = 0;
        if (global != 1) {
            bad = 1;
        }
        if ( aMin >= bMax || bMin >= aMax ) {
            bad = 1;
        }
        if (bad) {
            printf("Case %d: YES\n", tc);
        } else
            printf("Case %d: NO\n", tc);
        tc ++;
        
    }
    return 0;
    
}