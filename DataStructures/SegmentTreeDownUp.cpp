#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct SegTree {
    int t_size, *t;
    SegTree() {}
    SegTree(int n, int * src) {
        t_size = 1;
        while (t_size < n) t_size <<= 1;
        t = new int[2*t_size];
        for (int i = 0 ; i < 2*t_size ; i ++)
            t[i] = 1 << 30;
        build_tree(src, n);
    }
    void build_tree(int * src, int n)
    {
        /* leaves */
        for (int i = t_size ; i < 2*t_size ; i++)
            t[i] = i - t_size < n ? src[i - t_size] : (1 << 30);
        
        for (int i = t_size - 1; i > 0; i--)
            t[i] = min(t[2 * i], t[2 * i + 1]);

    }
    int getMax(int l, int r) {//0-based
        int ans = 1 << 30;
        l += t_size, r += t_size;
        while (l <= r)
        {
            if (l & 1)
                ans = min(ans, t[l]);
            if (!(r & 1))
                ans = min(ans, t[r]);
            l = (l + 1) / 2, r = (r - 1) / 2;
        }		
        return ans;
    }
    void update(int i, int x)//0-based
    {
        i += t_size;
        t[i] = x;
        while (i /= 2)
            t[i] = min(t[2 * i], t[2 * i + 1]);
    }
};
int a[100100];
int main() {
    freopen("stupid_rmq.in", "r", stdin);
    freopen("stupid_rmq.out", "w", stdout);
    int n, l, r, m;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++)
        scanf("%d", &a[i]);
    SegTree T(n, a);
    
    
    scanf("%d", &m);
    for (int q = 0 ; q < m ; q ++) {
        scanf("%d%d", &l, &r);
        l --; r --;
        printf("%d\n", T.getMax(l, r));
    }
    return 0;
}
