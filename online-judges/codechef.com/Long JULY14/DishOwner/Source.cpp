#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 10010;

int T, n, s[N];
int uf[N];
int mx[N], bel[N];

void init() {
    for (int i = 1 ; i <= n ; i ++) {
        uf[i] = bel[i] = i;
        
        mx[i] = s[i];
    }
}
int root(int x) {
    while (x != uf[x]) {
        uf[x] = uf[uf[x]];
        x = uf[x];
    }
    return x;
}
int unite(int x, int y) {
    //cout << "x, y=" << x << ',' << y << endl;
    x = root(x); y = root(y);
    //cout << "rx, ry=" << x << ',' << y << endl;
    //cout << "belx, ry= " << bel[x] << ',' << bel[y] << endl;
    //cout << "mxx, ry= " << mx[bel[x]] << ',' <<mx[bel[y]] << endl;
    if (bel[x] == bel[y])
        return -1;
    if (mx[bel[x]] < mx[bel[y]]) {
        mx[bel[x]] = mx[bel[y]];
        bel[x] = bel[y];
    } else if (mx[bel[x]] > mx[bel[y]]) {
        mx[bel[y]] = mx[bel[x]];
        bel[y] = bel[x];
    } else
        return 0;
    /*
    cout << "new\n";
    cout << "rx, ry=" << x << ',' << y << endl;
    cout << "belx, ry= " << bel[x] << ',' << bel[y] << endl;
    cout << "mxx, ry= " << mx[bel[x]] << ',' <<mx[bel[y]] << endl ;
     */
    if (rand() & 1) {
        uf[x] = y;
        //cout << "hung " << x << " under " << y << endl;
    } else {
        uf[y] = x;
        //cout << "hung " << y << " under " << x << endl;
    }
    //cout << endl;
    return 1;
}

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1 ; i <= n ; i ++)
            scanf("%d", &s[i]);
        init();
        int q;
        scanf("%d", &q);
        while (q --) {
            int t;
            scanf("%d", &t);
            if (t == 0) {
                int a, b;
                scanf("%d%d", &a, &b);
                if (unite(a, b) < 0)
                    puts("Invalid query!");
            } else {
                
                int a;
                scanf("%d", &a);
                a = root(a);
                printf("%d\n", bel[a]);
            }
            /*
            cout << "DEBUG\n";
            for (int i = 1 ; i <= n ; i ++)
                cout << bel[root(i)] << ' ';
            cout << endl;
            cout << "uf : " << endl;
            for (int i = 1; i <= n ; i ++)
                cout << uf[i] << ' ';
            cout << endl;*/
        }
        
    }
    
    
    
    
    return 0;
}