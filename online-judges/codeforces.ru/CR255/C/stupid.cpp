#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 400005, mod = 1000000009, Q = 600;

int f[N], a[N], sa[N], sf[N];
int n, m, q;


int main() {
    scanf("%d%d", &n, &m);
    q = (int)sqrt(m) + 1;
    f[1] = sf[1] = 1;
    for (int i = 2 ; i <= n + Q ; i ++) {
        f[i] = f[i - 1] + f[ i - 2 ];
        if (f[i] >= mod)
            f[i] -= mod;
        sf[i] = sf[i-1] + f[i]; if (sf[i] >= mod) sf[i] -= mod;
        
    }
    
    for (int i = 1 ; i <= n ; i ++) {
        scanf("%d", &a[i]);
        
        //cout << sa[i] << ' ';
    }
    for (int i = 0 ; i < m ; i ++) {
        int ty, l, r;
        scanf("%d%d%d", &ty, &l, &r);
        if (ty == 1) {
            for (int j = l, k = 1 ; j <= r ; j ++, k ++) {
                a[j] += f[k];
                a[j] %= mod;
            }
        } else {
            int res = 0;
            for (int j = l ; j <= r ; j ++)
                res += a[j], res %= mod;
            cout << res << endl;
        }
    }
    
    
    
    
    return 0;
}




