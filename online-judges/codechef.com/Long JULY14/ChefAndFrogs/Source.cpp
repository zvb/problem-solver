#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100100, inf = 1 << 30;
int n, k, p;
int a[N], d[N], loc[N];

pair<int, int> f[N];

int tree[4*N];
void build(int v, int L, int R) {
    if (L == R)
        tree[v] = d[L];
    else {
        int m = (R + L) >> 1;
        build(2*v, L, m);
        build(2*v + 1, m + 1, R);
        tree[v] = max(tree[2*v], tree[2*v + 1]);
    }
}
int get_max(int v, int L, int R, int l, int r) {
    if (l > r)
        return -inf;
    if (l == L && r == R)
        return tree[v];
    int mid = (L + R) >> 1;
    return max(get_max(2*v, L, mid, l, min(r, mid)),
               get_max(2*v+1, mid + 1, R, max(mid + 1, l), r));
}


int main() {
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0 ; i < n ; i ++) {
        scanf("%d", &a[i]);
        f[i] = make_pair(a[i], i);
    }
    sort(f, f + n);
    
    for (int i = 0 ; i < n ; i ++) {
        loc[f[i].second] = i;
        if (i > 0) {
            d[i-1] = f[i].first - f[i-1].first;
            //cout << d[i - 1] << ' ';
        }
    }
    //cout << endl;
    if (n > 1)
        build(1, 0, n - 2);
    for (int i = 0 ; i < p ; i ++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l --; r --;
        
        if (n == 1) {
            puts("Yes");
            continue;
        }
        
        //cout << "locations : " << loc[l] << ' ' << loc[r] << endl;
        int left = min(loc[l], loc[r]), right = max(loc[l], loc[r]);
        
        if (left == right) {
            puts("Yes");
            continue;
        }
        if (right - 1 < 0) {
            puts("Yes");
            continue;
        }
        int btneck = get_max(1, 0, n - 2, left, right - 1);
        //cout << "btneck = " << btneck << endl;
        if (btneck <= k)
            puts("Yes");
        else
            puts("No");
    }
    
    

    return 0;
}