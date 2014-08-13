#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;
const int N = 800000 + 5, M = 200000 + 5;

#define mx(a, b) (a < b ? b : a)
#define mn(a, b) (a < b ? a : b)

struct event {
    int x, opening, id;
    bool operator<(const event& o) const {
        return x < o.x || (x == o.x && id < o.id);
    }
};

int len(int x) {
    if (x >= 1000) return 4;
    if (x >= 100) return 3;
    if (x >= 10) return 2;
    return 1;
}

struct SegTree {
    int t_size, *t;
    SegTree() {}
    SegTree(int n, int * src) {
        t_size = 1;
        while (t_size < n) t_size <<= 1;
        t = new int[2*t_size];
        for (int i = 0 ; i < 2*t_size ; i ++)
            t[i] = -1;
        build_tree(src, n);
    }
    void build_tree(int * src, int n)
    {
        /* leaves */
        for (int i = t_size ; i < 2*t_size ; i++)
            t[i] = i - t_size < n ? src[i - t_size] : (-1);
        
        for (int i = t_size - 1; i > 0; i--)
            t[i] = t[2 * i] > t[2 * i + 1] ? t[2*i] : t[2*i+1];
    }
    void update_all() {
        for (int i = t_size - 1; i > 0; i--)
            t[i] = t[2 * i] > t[2 * i + 1] ? t[2*i] : t[2*i+1];
    }
    int getMax(int l, int r) {//0-based
        int ans = -1;
        l += t_size, r += t_size;
        while (l <= r)
        {
            if (l & 1) {
                if (ans < t[l])
                    ans = t[l];
            }
            if (!(r & 1)) {
                if (ans < t[r])
                    ans = t[r];
            }
            l = (l + 1) >> 1, r = (r - 1) >> 1;
        }
        return ans;
    }
};

int a[12][N], ten[5];
int n, m;
SegTree F[12];
int Q;
int force[M];
int aux[N];


int main() {
    //long long ts = time(0);
    ten[0] = 1; for (int i = 1 ; i <= 4 ; i++) ten[i] = ten[i-1]*10;
    ios_base::sync_with_stdio(0);
    cin >> n;
    int log_n = 0;
    while ( (1 << log_n) < n) log_n ++;
    
    for (int i = 0 ; i < n ; i++) {
        cin >> a[0][i];
        int l = len(a[0][i]);
        for (int j = 1 ; j < 12 ; j++)
            a[j][i] = a[j-1][i] / ten[l-1] + 10*(a[j-1][i] % ten[l-1]);
    }
    for (int j = 0 ; j < 12 ; j ++)
        F[j] = SegTree(n, a[j]);
    cin >> m;
    //Q = (int)sqrt(n*m) + 1;
    Q = (int)sqrt(16*n) + 1;
    for (int q = 0 ; q < m ; q += Q) {
        int type, l, r, f;
        set<event> st;
        for (int i = 0 ; i < Q && i + q < m ; i ++) {
            cin >> type;
            if (type) {
                cin >> l >> r; r++;
                int res = -1;
                if (st.empty()) {
                    int q = F[0].getMax(l, r - 1);
                    if (q > res)
                        res = q;
                }
                int last = 0, curf = 0;
                for (set<event>::iterator it = st.begin() ; it != st.end() ; it ++) {
                    if (it->x < l) {
                        int q = F[curf].getMax( mx(last, l), mn(it->x, r) - 1);
                        if (q > res) res = q;
                    }
                    else if (it->x >= l && it->x <= r) {
                        int q = F[curf].getMax( mx(last, l), mn(it->x, r) - 1);
                        if (q > res) res = q;
                    } else if (it->x > r) {
                        int q = F[curf].getMax( mx(last, l), mn(it->x, r) - 1);
                        if (q > res) res = q;
                        break;
                    }
                    
                    if (it->opening) curf += force[it->id];
                    else curf -= force[it->id];
                    if (curf < 0) curf += 12;
                    else if (curf >= 12) curf -= 12;
                    last = it->x;
                }
                int q = F[curf].getMax( mx(last, l), r - 1);
                if (q > res) res = q;
                
                cout << res << endl;
                
            } else {
                cin >> l >> r >> f;
                f %= 12;
                force[i + q] = f;
                event op = {l, 1, i + q};
                event cl = {r + 1, 0, i + q};
                st.insert(op); st.insert(cl);
            }
        }
        memset(aux, 0, sizeof(int)*(n+5));

        for (set<event>::iterator it = st.begin() ; it != st.end() ; it ++) {
            if (it->opening) {
                aux[it->x] += force[it->id];
                if (aux[it->x] >= 12) aux[it->x] -= 12;
            }
            else {
                aux[it->x] += -force[it->id];
                if (aux[it->x] < 0) aux[it->x] += 12;
            }
        }
        int fi = st.begin()->x, se = st.rbegin()->x;
        
        int curf = 0;
        int car[12];
        int t_size = F[0].t_size;
        for (int i = fi ; i < se ; i++) {
            curf += aux[i]; if (curf >= 12) curf -= 12;
            
            for (int j = 0 ; j < 12 ; j ++)
                car[j] = F[(j + curf) < 12 ? j + curf : curf + j - 12].t[i + t_size];
            for (int j = 0 ; j < 12 ; j ++)
                F[j].t[i + t_size] = car[j];
        }
        for (int j = 0 ; j < 12 ; j ++)
            F[j].update_all();
    }
    //ts = time(0) - ts;
    //cerr << ts << endl;
    
    
    return 0;
}