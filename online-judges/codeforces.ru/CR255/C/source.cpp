#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 400005, mod = 1000000009, Q = 600;

int f[N], a[N], sa[N], sf[N];
int n, m, q;

pair<int, int> v[Q + 5]; int vn = 0;

struct event {
    int ind, opening, x;
    bool operator<(const event& o) const {
        return x < o.x;
    }
};
event e[2*Q + 5]; int en = 0;

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
        sa[i] = sa[i - 1] + a[i]; if (sa[i] >= mod) sa[i] -= mod;
        //cout << sa[i] << ' ';
    }
    
    for (int z = 0 ; z < m ; z += q) { //
        for (int y = 0 ; y < q && z + y < m ; y ++) { // y = query number within a block
            int ty, l, r;
            scanf("%d%d%d", &ty, &l, &r);
            if (ty == 2) {// ?
                int res = sa[r] - sa[l-1];
                
                if (res < 0) res += mod;
                else if (res >= mod) res -= mod;
                
                for (int i = 0 ; i < vn ; i ++) {
                    int lo = v[i].first, hi = v[i].second;
                    if (lo > r || hi < l)
                        continue;
                    int u = max(l, lo), v = min(hi, r);
                    res += sf[v-lo+1]; if (res >= mod) res -= mod;
                    res -= sf[u-lo]; if (res < 0) res += mod;
                    //res += sf[v-lo+1] - sf[u-lo];
                    //if (res < 0) res += mod;
                    //else if (res >= mod) res -= mod;
                }
                printf("%d\n", res);
            } else { // +
                v[vn ++] = make_pair(l, r);
            }
        }
        for (int i = 0 ; i < vn ; i ++) {
            //cout << v[i].first << ' ' << v[i].second << endl;
            event ce = {i, 1, v[i].first};
            e[en ++] = ce;
            ce.opening = 0; ce.x = v[i].second + 1;
            e[en ++] = ce;
        }
        sort(e, e + en);
        int U = 0, V = 0, tmp = 0;
        int p = 0;
        for (int i = 1 ; i <= n ; i ++) {
            int W = V + U; if (W >= mod) W -= mod;
            if (i < e[p].x) {
                //cout << "no event at i = " << i << ". added " << W << " to a" << endl;
                a[i] += W; if (a[i] >= mod) a[i] -= mod;
                U = V; V = W;
            } else {
                while (p < en && e[p].x == i) {
                    // prcess event
                    //cout << "processing event at i = " << i << " pos = " << e[p].x << endl;
                    if (e[p].opening) {
                        W ++; if (W >= mod) W -= mod;
                        //cout << "opening W now is " << W << " V, U = " << V << ", " << U << endl;
                    } else {
                        int l = v[e[p].ind].first, r = v[e[p].ind].second;
                        W -= f[r - l + 2]; if (W < 0) W += mod;
                        V -= f[r - l + 1]; if (V < 0) V += mod;
                        //cout << "closing W now is " << W << " V, U = " << V << ", " << U << endl;
                    }
                    p ++;
                }
                a[i] += W; if (a[i] >= mod) a[i] -= mod;
                U = V; V = W;
            }
            sa[i] = sa[i-1] + a[i]; if (sa[i] >= mod) sa[i] -= mod;
        }
        
        vn = en = 0;
    }
    
    
    return 0;
}




