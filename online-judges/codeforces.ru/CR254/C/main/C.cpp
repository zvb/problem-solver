#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>

using namespace std;

const int N = (int)1e5 + 100;

struct seg {
    int first, second;
    int w;
    seg() {}
    seg(int _f, int _s, int _w): first(_f), second(_s), w(_w) {}
    bool operator<(const seg& o) const {
        if (first < o.first) return 1;
        if (first > o.first) return 0;
        return second < o.second;
    }
};

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

vector< seg > del, add;

void print(set< seg >& s) {
    for (set< seg >::iterator it = s.begin() ; it != s.end() ; it ++)
        printf("[%d,%d](%d) ", it->first, it->second, it->w);
    puts("");
}
void print(seg s) {
    printf("[%d,%d](%d) ", s.first, s.second, s.w);
}


int main() {
    set<seg> s;
    int n, m;
    scanf("%d%d", &n, &m);
    SegTree t(n);

    for (int i = 1 ; i <= n ; i ++)
        s.insert(seg(i, i, i));
    
    //s.upper_bound(seg(1, 1, 0));
    //print(s);
    for (int q = 0 ; q < m ; q ++) {
        int type, l, r, x;
        scanf("%d", &type);
        //cout << "Before " ;
        //print(s);
        if (type == 1) {
            scanf("%d%d%d", &l, &r, &x);
            
            
            //cout << l << ' ' << r << ' ' << x << endl;
            
            set< seg >::iterator it = s.upper_bound(seg(l, 1 << 30, 0));
            //assert(it != s.end());
            //print(*it);
            
            it --;
            if (l - 1 >= it->first)
                add.push_back(seg(it->first, l - 1, it->w));
            
            
            
            while (it != s.end() && r >= it->first) {
                t.add(1, 0, n - 1, max(l, it->first) - 1,
                      min(r, it->second) - 1, abs(it->w - x));
                del.push_back(*it);
                it ++;
            }
            // TODO:
            if (it == s.end()) {
                // done
                it --;
                if (it->second >= r + 1)
                    add.push_back(seg(r + 1, it->second, it->w));
            } else {
                it --;
                if (it->second >= r + 1)
                    add.push_back(seg(r + 1, it->second, it->w));
            }
            add.push_back(seg(l, r, x));
            for (int i = 0 ; i < del.size(); i ++)
                s.erase(s.find(del[i]));
            for (int i = 0 ; i < add.size() ; i ++)
                s.insert(add[i]);
            add.clear(); del.clear();
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld\n", t.get(1, 0, n - 1, l - 1, r - 1));
            
        }
        //cout << "After " ;
        //print(s);
        //puts("");
        
    }
    
   
    
    return 0;
}