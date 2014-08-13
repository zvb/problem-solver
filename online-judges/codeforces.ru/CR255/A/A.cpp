#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = (int)1e5 + 100;

int n, a[N], l[N], r[N];

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i ++)
        scanf("%d", &a[i]);
    int curmx = 0;
    int best = 0;
    a[0] = -(1 << 30);
    for (int i = 1 ; i <= n ; i ++) {
        if (a[i] > a[i-1]) {
            l[i] = l[i-1] + 1;
        } else
            l[i] = 1;
    }
    a[n + 1] = 1 << 30;
    for (int i = n ; i >= 1 ; i --) {
        if (a[i] < a[i+1])
            r[i] = r[i+1] + 1;
        else
            r[i] = 1;
    }
    for (int i = 1 ; i <= n ; i ++) {
        if (best < r[i])
            best = r[i];
        if (best < l[i])
            best = l[i];
    }
    for (int i = 1 ; i<= n ; i++) {
        if (i > 1 ) {
            best = max(best, l[i-1] + 1);
        }
        if (i < n) {
            best = max(best, r[i+1] + 1);
        }
    }
//    for (int i = 1 ; i <= n ; i ++) {
//        if (i < n && best < r[i] + 1)
//            best = r[i] + 1;
//        if (best < l[i] + 1)
//            best = l[i] + 1;
//    }
//    cerr << best << endl;
    for (int i = 1 ; i <= n ; i ++) {
        
        if (a[i-1] + 2 <= a[i+1]) {
            best = max(best, l[i-1] + r[i+1] + 1);
        }
    }
    cout << best << endl;
    
    
    return 0;
}