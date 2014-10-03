#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int p = (int)1e9 + 9;
//const int p = 3;
const int N = (int)2e5 + 100;

int n, w, a[N], b[N], d[N];

long long x = 0;
long long hv[N];
long long cv[N];
long long pp[N];

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 0 ; i < n ; i ++) {
        scanf("%d", &a[i]);
        if (i) {
            d[i] = a[i] - a[i-1];
            pp[i] = pp[i-1] * p;
            hv[i] = pp[i] * d[i];
            cv[i] = cv[i-1] + hv[i];
            //cout << cv[i] << ' ' ;
        } else {
            pp[0] = 1;
            
        }
    }
    if (w == 1) {
        cout << n << endl;
        return 0;
    }
    //cout << endl;
    for (int i = 0 ; i < w; i ++) {
        scanf("%d", &b[i]);
        if (i) {
            x += pp[i-1] * (b[i] - b[i-1]);
        }
    }
    //cout << "x = " << x << endl;
    int m = n - 1;
    int ans = 0;
    for (int i = 1 ; i <= m ; i ++) {
        if (w + i - 1 <= n) {
            long long target = cv[w-1+i-1] - cv[i-1];
            //cout << "target = " << target << endl;
            //cout << "orig = " << x * pp[i] << endl;
            if (x * pp[i] == target)
                ans ++;
        }
    }
    cout << ans << endl;
    
    
    
    return 0;
}