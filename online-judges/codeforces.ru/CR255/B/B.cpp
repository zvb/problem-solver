#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int N = (int)1e3 + 10;
int n, m, k, p, a[N][N];
int r[N], c[N];
int br[N*N], bc[N*N];
priority_queue<int> rq, cq;

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 1 ; i <=n ; i ++)
        for (int j = 1; j <= m ;j ++)
            scanf("%d", &a[i][j]);
    
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j ++) {
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }
    for (int i = 1 ; i <= n ; i ++)
        rq.push(r[i]);
    for (int j = 1 ; j <= m ; j ++)
        cq.push(c[j]);
    
    for (int i = 1 ; i <= k ; i ++) {
        br[i] = rq.top(); rq.pop();
        rq.push(br[i] - m*p);
    }
    for (int i = 1 ; i <= k ; i ++) {
        bc[i] = cq.top(); cq.pop();
        cq.push(bc[i] - n*p);
    }
    /*
    for (int i = 1 ; i <= k ; i ++)
        cout << br[i] << ' ';
    cout << endl;
    for (int i = 1 ; i <= k ; i ++) cout << bc[i] << ' '; cout << endl;
     */
    
    long long curR = 0, curC = 0;
    long long best = -(1ll << 60);
    for (int i = 1 ; i <= k ; i ++)
        curC += bc[i];
    for (int x = 0 ; x <= k ; x ++) {
        long long rel = curR + curC - 1ll * x * (k - x) * p;
        //cout << "curR = " << curR << " , curC = " << curC << endl;
        //cout << "rel = " << rel << endl;
        best = best < rel ? rel : best;
        curR += br[x + 1];
        curC -= bc[k - x];
    }
    cout << best << endl;
    

    
    
    return 0;
}