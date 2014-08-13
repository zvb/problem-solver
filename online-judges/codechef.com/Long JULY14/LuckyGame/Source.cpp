#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

const int N = 1010;

int n, m, p[N], u[N];
vector<int> g[N];
int was[N*N];

double getp(int a, int b) {
    double res = 0.0;
    for (int i = 0 ; i < m ; i ++) {
        for (int j = 0 ; j < m ; j ++) {
            if (g[a][i] > g[b][j])
                res = res + 1.0;
        }
    }
    //cout << res / m / m << endl;
    return res / m / m;
}

int arr[12] = {1, 3, 10, 11, 2, 7, 8, 9, 4, 5, 6, 12};

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0 ; i < n ; i ++) {
        scanf("%d", &p[i]);
        g[i].clear();
        u[i] = 0;
    }
    for (int i = 1 ; i <= n * m ; i ++)
        was[i] = 0;
    
    if (m <= 2 || n <= 2)
    {
        puts("No Solution");
        return;
    }
    //{1, 3, 10, 11,
    // 2, 7, 8, 9,
    // 4, 5, 6, 12}

    int cur = n*m;
    for (int i = 0 ; i < n ; i ++) {
        if (u[i]) continue;
        vector<int> ind;
        int ii = i, k = 0;
        do {
            u[ii] = 1;
            ind.push_back(ii);
            ii = p[ii];
            k ++;
        } while (ii != i);
        
        if (k <= 2) {
            puts("No Solution");
            return;
        }
        if (k == 3 && m == 4) {
            cur -= 12;
            for (int j = 0 ; j < k ; j ++) {
                for (int c = 0 ; c < m ; c ++) {
                    g[ind[j]].push_back(cur + arr[j * m + c]);
                }
                reverse(g[ind[j]].begin(), g[ind[j]].end());
            }
            
            continue;
        }

        
        for (int c = 0 ; c < m ; c ++) {
            int ss = (c) % k;
            for (int j = ss ; j < k ; j ++)
                g[ind[j]].push_back(cur --);
            for (int j = 0 ; j < ss ; j ++)
                g[ind[j]].push_back(cur --);
        }
        /*
        for (int c = 0 ; c < k ; c ++) {
            int j = c + 1; if (j == k) j = 0;
            printf("prob of %d winning %d is = %lf\n", ind[c], ind[j], getp(ind[c], ind[j]));
        }
        */
    }
    for (int i = 0 ; i < n ; i ++) {
        reverse(g[i].begin(), g[i].end());
        //double pr = getp(i, p[i]); // Time limit O(n^3)
        //assert(pr > .5);
        //if (pr <= .5)
          //  cout << "ERROR: n=" << n << ", m = " << m << endl;
        //printf("prob of %d winning %d is = %lf\n", i, p[i], getp(i, p[i]));
        
        for (int j = 0 ; j < m ; j ++) {
            printf("%d", g[i][j]);
            if (j < m - 1)
                printf(" ");
            assert(g[i][j] >= 1 && g[i][j] <= n * m);
            assert(!was[g[i][j]]);
            was[g[i][j]] = 1;
            if (j > 0)
                assert(g[i][j-1] < g[i][j]);
        }
        puts("");
    }
    //cout << "OK" << endl;
}


int main() {
    
    int T;
    scanf("%d", &T);
    while (T --)
        solve();
/*
    int cur = 1;
    for (int i = 0 ; i < m ; i ++) {
        int ss = i % k + 1;
        for (int j = ss ; j <= k ; j ++)
            g[j].push_back(cur ++);
        for (int j = 1 ; j <= ss - 1 ; j ++)
            g[j].push_back(cur ++);
        
    }
    for (int i = 1 ; i <= k ; i ++) {
        for (int j = 0 ; j < m ; j ++)
            cout << g[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    for (int i = 1 ; i <= k ; i ++) {
        int j = i + 1; if (j == k + 1) j = 1;
        printf("prob of %d winning %d is = %lf\n", j, i, getp(j, i));
    }
    */
    
    return 0;
}