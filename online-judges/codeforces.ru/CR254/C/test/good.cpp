#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>

using namespace std;

struct SegTree {
    int n;
    long long *a, *f;
    SegTree() {}
    SegTree(int _n) {
        n = _n;
        a = new long long [4*n];
        f = new long long [4*n];
        for (int i = 0 ; i < 4*n ; i ++)
            a[i] = f[i] = 0;
    } // invariant: if f[v] == 0, then a[v] is correctly computed.
    void push(int v, int L, int R) {
        if (f[v] == 0)
            return;
        if (L == R) {
            a[v] += f[v];
            f[v] = 0;
        } else {
            f[2*v] += f[v];
            f[2*v + 1] += f[v];
            a[v] += (R - L + 1) * f[v];
            f[v] = 0;
        }
    }
    void add(int v, int L, int R, int l, int r, int val) {
        push(v, L, R);
        if (l > r) return;
        if (l == L && r == R) {
            f[v] += val;
        } else {
            int m = (L + R) >> 1;
            add(2*v, L, m, l, min(r, m), val);
            add(2*v + 1, m + 1, R, max(l, m + 1), r, val);
            push(2*v, L, m); push(2*v+1, m + 1, R);
            a[v] = a[2*v] + a[2*v+1];
        }
        push(v, L, R);
    }
    long long get(int v, int L, int R, int l, int r) {
        push(v, L, R);
        if (l > r) return 0;
        if (l == L && r == R) {
            return a[v];
        } else {
            int m = (L + R) >> 1;
            return get(2*v, L, m, l, min(r, m)) +
            + get(2*v + 1, m + 1, R, max(l, m + 1), r);
        }
    }
    
};

int a[200000];

int main() {
    
    int n, m;
    scanf("%d%d", &n, &m);
    SegTree T(n);
    
    for (int i = 0 ; i < m ; i ++) {
        int t, l, r, x;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &l, &r);
            
            printf("%d\n", (int)T.get(1, 0, n-1, l, r));
        } else {
            scanf("%d%d%d", &l, &r, &x);
            T.add(1, 0, n - 1, l, r, x);
        }
    }
    
    
    
    return 0;
}