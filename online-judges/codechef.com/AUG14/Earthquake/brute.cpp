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


int a[12][N], ten[5];
int n, m;
int state[N];


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
    cin >> m;
    for (int q = 0 ; q < m ; q ++) {
        int type, l, r, f;
        cin >> type;
        if (type) {
            cin >> l >> r;
            int res = -1;
            for (int i = l ; i <= r ; i++) {
                res = max(res, a[state[i]][i]);
            }
            cout << res << endl;
        } else {
            cin >> l >> r >> f;
            for (int i = l ; i <= r ; i++)
                state[i] = (state[i] + f)%12;
        }
    }
    
    
    
    return 0;
}