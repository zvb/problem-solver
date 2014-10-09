#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

const int N = 505;



struct Dsu {
    int *id, sz, n;
    Dsu() {}
    void init() {
        sz = n;
        for (int i = 0 ; i < n ; i++)
            id[i] = i;
    }
    Dsu (int _n) {
        id = new int[_n];
        n = _n;
        sz = n;
        init();
    }
    int root(int x) {
        while (x != id[x]) {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }
    void unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y)
            return;
        sz --;
        if (rand() & 1)
            id[x] = y;
        else
            id[y] = x;
    }
};

struct edge {
    int a, b, c;
    bool operator<(const edge& o) const {
        return c < o.c;
    }
};

int n, m;

edge e[N*N];





vector<int> mst;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0 ; i < m ; i ++) {
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
        e[i].a --;
        e[i].b --;
    }
    
    
    Dsu dsu1(n);
    sort(e, e + m);
    
    int cost = 0;
    for (int i = 0 ; i < m ; i ++) {
        if (dsu1.root(e[i].a) != dsu1.root(e[i].b)) {
            dsu1.unite(e[i].a, e[i].b);
            cost += e[i].c;
            mst.push_back(i);
            //cout << "united " << e[i].a << ' ' << e[i].b << endl;
        }
    }
    printf("Cost: %d\n", cost);
    int bestCost = 1 << 30;
    
    for (int j = 0; j < mst.size() ; j ++) {
        int removed = mst[j];
        dsu1.init();
        //cout << "after init\n";
        cost = 0;
        for (int i = 0 ; i < m ; i ++) {
            if (removed != i && dsu1.root(e[i].a) != dsu1.root(e[i].b)) {
                dsu1.unite(e[i].a, e[i].b);
                cost += e[i].c;
                //cout << "united " << e[i].a << ' ' << e[i].b << endl;
            }
        }
        //cout << "j = " << j << endl;
        if (dsu1.sz == 1)
            bestCost = min(cost, bestCost);
    }
    if (bestCost < (1 << 30) )
        printf("Cost: %d\n", bestCost);
    else
        puts("Cost: -1");
    return 0;
}





