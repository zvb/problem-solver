#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    //scanf("%d%d", &n, &m);
}

int m = 4;
int k = 3;
vector<int> g[10];

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

int p[20];
int main() {

    for (int i = 0 ; i < m*k ; i ++)
        p[i] = i + 1;
    do {
        bool ok = 1;
        for (int i = 0 ; i < k ; i ++) {
            g[i].clear();
            for (int j = 0 ; j < m ; j ++)
                g[i].push_back(p[i*m + j]);

        }
        for (int i = 0 ; i < k ; i ++) {
            int j = i + 1; if (j == k) j = 0;
            if (getp(i, j) <= .5)
                ok = 0;
        }
        //cout << endl;
        if (ok) {
            for (int i = 0 ; i < m*k ; i ++)
                cout << p[i] << ' ';
            cout << endl;
            break;
        }
    } while (next_permutation(p, p + m*k));
    
    
    /*
    int T;

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