#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

#define N 444
using namespace std;

int t, n, m, q[N], c[N], p[N];

set<pair<int, int> >::iterator contains(set<pair<int, int> >& st, int val) {
    for (set<pair<int, int> >::iterator it = st.begin() ; it != st.end() ; it++)
        if (it->second == val)
            return it;
    return st.end();
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        memset(c, 0, sizeof(c));
        for (int i = 1 ; i <= m ; i ++)
            scanf("%d", &q[i]);
        for (int i = m ; i >= 1; i -- ) {
            if (c[q[i]] == 0)
                p[i] = -444, c[q[i]] = i;
            else
                p[i] = -c[q[i]], c[q[i]] = i;
        }
        set< pair<int, int> > table;
        int res = 0;
        for (int i = 1 ; i <= m ; i ++) {
            if (table.size() < n) {
                set<pair<int, int> >::iterator it = contains(table, q[i]);
                if (it != table.end())
                    table.erase(it);
                else
                    res ++;
                table.insert(make_pair(p[i], q[i]));
            } else {
                set<pair<int, int> >::iterator it = contains(table, q[i]);
                if (it != table.end()) {
                    table.erase(it);
                    table.insert(make_pair(p[i], q[i]));
                } else {
                    table.erase(table.begin());
                    table.insert(make_pair(p[i], q[i]));
                    res ++;
                }
            }
            
        }
        printf("%d\n", res);
    }
    
    return 0;
}