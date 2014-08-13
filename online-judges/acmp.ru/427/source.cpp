#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
#define N 10005
#define L 300000

int a[N], n;

vector< pair<long long, long long> > v, u, w;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i ++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    u.reserve(L); v.reserve(L); w.reserve(L);
    
    
    v.push_back(make_pair(0, 0));
    for (int i = 0 ; i < n ; i ++) {
        
        
        
        // pre: v is sorted and v.size > 0, u, w are empty;
        for (int j = 0 ; j < v.size() ; j ++)
            u.push_back(make_pair(v[j].first + a[i], v[j].second + a[i]));
        
        int pv = 0, pu = 0;
        for ( ; pu < u.size() && pv < v.size() ; pu ++) {
            while (pv < v.size() && v[pv].second + 1 < u[pu].first) {
                w.push_back(v[pv]);
                pv ++;
            }
            if (pv >= v.size()) {
                w.push_back(u[pu]);
                continue;
            }
            int l = min(u[pu].first, v[pv].first);
            while (pv + 1 < v.size() && v[pv + 1].first <= u[pu].second + 1)
                pv ++;
            int r = max(u[pu].second, v[pv].second);
            w.push_back(make_pair(l, r));
            pv ++;
        }
        while (pu < u.size())
            w.push_back(u[pu ++]);
        
        swap(v, w);
        u.clear(), w.clear();
        /*
        for (int j = 0 ; j < v.size(); j ++)
            cout << '[' << v[j].first << ", " << v[j].second << ']' << ' ';
        cout << endl;
         */
    }
    cout << v[0].second + 1 << endl;
    
    return 0;
}