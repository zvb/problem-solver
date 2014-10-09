#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = (int)1e5 + 10;

int logN[N];

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

struct SparseTable {
    int **d;
    SparseTable() {}
    SparseTable(int n, int *a) {
        int logn = logN[n] + 1;
        d = new int*[logn];
        for (int i = 0 ; i < logn ; i ++)
            d[i] = new int [n];
        for (int i = 0 ; i < n ; i ++)
            d[0][i] = a[i];
        for (int i = 1 ; i < logn ; i ++) {
            for (int j = 0 ; j + (1 << (i-1)) < n ; j ++) {
                d[i][j] = gcd(d[i-1][j], d[i-1][j + (1 << (i-1))]);
            }
        }
    }
    int get(int l, int r) {
        r ++;
        int lg = logN[r - l];
        return gcd(d[lg][l], d[lg][r-(1<<lg)]);
    }
};

map<int, long long> cnt;

int n, a[N];

set<int> QS;
int qs[3*N], q = 0;

int sieve[N];
map<int, int> primes;


int main() {
    
    for (int i = 1, j = 0; i < N ; i++) {
        if ( (1 << (j + 1)) <= i )
            j ++;
        logN[i] = j;
    }
    
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> a[i];
    SparseTable t(n, a);
    cin >> q;
    for (int i = 0 ; i < q ; i ++) {
        cin >> qs[i];
        QS.insert(qs[i]);
    }
    for (int i = 0 ; i < n ; i ++) {
        int j = i;
        int d = 0;
        //cout << "i = " << i << endl;
        while (j < n) {
            d = t.get(i, j);
            int old_j = i;
            //cout << "d = " << d << endl;
            int lo = j, hi = n, mid;
            while (hi > lo) {
                mid = (lo + hi) >> 1;
                if (t.get(i, mid) == d)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            old_j = j;
            j = lo;
            //cout << "j = " << j << endl;
            if (QS.count(d) != 0) {
                cnt[d] += j - old_j;
            }
        }
        cout << endl;
    }
    for (int i = 0 ; i < q ; i ++) {
        cout << cnt[qs[i]] << '\n';
    }
    
    return 0;
}







