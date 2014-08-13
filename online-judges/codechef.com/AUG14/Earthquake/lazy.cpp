#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;
const int N = 800000 + 5, M = 200000 + 5;


int len(int x) {
    if (x >= 1000) return 4;
    if (x >= 100) return 3;
    if (x >= 10) return 2;
    return 1;
}


struct tnode {
    int a[12];
};

int tmp[12];

struct SegTree {
    int n, *f;
    tnode *t;
    SegTree() {}
    SegTree(int src[][N], int _n) {
        n = _n;
        t = new tnode [4*n];
        f = new int [4*n];
        memset(f, 0, sizeof(int)*4*n);
        build(1, 0, n - 1, src);
    }
    void build(int v, int L, int R, int src[][N]) {
        if (L == R) {
            for (int i = 0 ; i < 12 ; i ++)
                t[v].a[i] = src[i][L];
        }
        else {
            int mid = (L + R) >> 1;
            build(2*v, L, mid, src);
            build(2*v+1, mid + 1, R, src);
            for (int i = 0 ; i < 12 ; i ++)
                t[v].a[i] = max(t[2*v].a[i], t[2*v+1].a[i]);
        }
    }
    void push(int v, int L, int R) {
        if (f[v] == 0)
            return;
        if (L == R) {
            for (int i = 0 ; i < 12 ; i ++)
                tmp[i] = t[v].a[(i + f[v])%12];
            for (int i = 0 ; i < 12 ; i ++)
                t[v].a[i] = tmp[i];
            f[v] = 0;
        } else {
            for (int i = 0 ; i < 12 ; i ++)
                tmp[i] = t[v].a[(i + f[v])%12];
            for (int i = 0 ; i < 12 ; i ++)
                t[v].a[i] = tmp[i];
            f[2*v] += f[v]; f[2*v] %= 12;
            f[2*v + 1] += f[v]; f[2*v+1] %= 12;
            f[v] = 0;
        }
    }
    void shake(int v, int L, int R, int l, int r, int val) {
        push(v, L, R);
        if (l > r) return;
        if (l == L && r == R) {
            f[v] += val; f[v] %= 12;
        } else {
            int m = (L + R) >> 1;
            shake(2*v, L, m, l, min(r, m), val);
            shake(2*v + 1, m + 1, R, max(l, m + 1), r, val);
            push(2*v, L, m); push(2*v+1, m + 1, R);
            for (int i = 0 ; i < 12 ; i ++)
                t[v].a[i] = max(t[2*v].a[i], t[2*v+1].a[i]);
        }
        push(v, L, R);
    }
    long long get(int v, int L, int R, int l, int r) {
        push(v, L, R);
        if (l > r) return 0;
        if (l == L && r == R) {
            return t[v].a[0];
        } else {
            int m = (L + R) >> 1;
            return max(get(2*v, L, m, l, min(r, m)),
            get(2*v + 1, m + 1, R, max(l, m + 1), r));
        }
    }
    
};


int a[12][N], ten[5];
int n, m;
SegTree T;
int Q;



int main() {
    
    ten[0] = 1; for (int i = 1 ; i <= 4 ; i++) ten[i] = ten[i-1]*10;
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    
    
    for (int i = 0 ; i < n ; i++) {
        cin >> a[0][i];
        int l = len(a[0][i]);
        for (int j = 1 ; j < 12 ; j++)
            a[j][i] = a[j-1][i] / ten[l-1] + 10*(a[j-1][i] % ten[l-1]);
    }
    T = SegTree(a, n);
    cin >> m;
    int type, l, r, f;
    while (m --) {
        cin >> type;
        if (type) {
            cin >> l >> r;
            cout << T.get(1, 0, n - 1, l, r) << '\n';
        } else {
            cin >> l >> r >> f;
            T.shake(1, 0, n - 1, l, r, f%12);
        }
    }
    
    
    return 0;
}