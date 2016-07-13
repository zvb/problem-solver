#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int mod = (int)1e9 + 7;

struct matrix {
    vector< vector<int> > data;
    matrix() {}
    matrix(int n, int m) {
        data.resize(n);
        for (int i = 0 ;i < n; i ++)
            data[i].resize(m);
    }
    matrix operator*(const matrix& o) const  {
        assert(data[0].size() == o.data.size());
        matrix res(data.size(), o.data[0].size());
        for (int i = 0 ; i < data.size() ; i++) {
            for (int j = 0 ; j < o.data[0].size(); j ++) {
                for (int k = 0 ; k < data[0].size() ; k ++) {
                    
                    res.data[i][j] += (1ll*data[i][k] * o.data[k][j])%mod;
                    res.data[i][j] = ((res.data[i][j])%mod + mod) %mod;
                }
            }
        }
        return res;
    }
    void print() {
        for (int i = 0 ; i < data.size() ; i++) {
            for (int j = 0 ; j < data[0].size() ; j++) {
                printf("%02d ", data[i][j]);
            }
            puts("");
        }
    }
};

matrix eye;


matrix binpow(matrix t, long long p) {
    matrix res(41, 41);
    for (int i = 0 ; i <41 ;i++)
        res.data[i][i] = 1;
    while (p) {
        if (p & 1)
            res = res * t;
        t = t * t;
        p >>= 1;
    }
    return res;
}

long long n;

int f(long long n) {
    return ((n/25 + 1) * (n/5 + 1) - 5 * (n/25) * (n/25 + 1) / 2)%mod;
}

int calc(long long n ) {
    long long ans = 0;
    for (int i = 0 ; i <= n ; i += 10)
        ans = (ans + f(n - i))%mod;
    return ans;
}

matrix a0(41, 1);
matrix t(41, 41);

int v[4] = {1, 5, 10, 25};

int main() {
    
    cin >> n;
    
    
    
    
    for (int i = 41 ; i >= 1 ; i --) {
        a0.data[i-1][0] = calc(41 - i + 1);
        //cout << "i = " << i << ' ' << a0.data[i-1][0] << endl;
    }
    for (int mask = 0 ; mask < (1 << 4) ; mask ++) {
        if (!mask) continue;
        int sum = 0, cnt = 0;;
        for (int i = 0 ; i < 4; i ++) {
            if (mask & (1 << i))
                sum += v[i], cnt ++;
        }
        if (cnt & 1) {
            t.data[0][sum - 1] = 1;
        } else {
            t.data[0][sum - 1] = mod-1;
        }
        
    }
    for (int i = 1 ; i < t.data.size() ; i++) {
        t.data[i][i-1] = 1;
    }
    /*
    for (int i = 0 ; i < t.data[0].size() ; i++) {
        printf("%02d ", i);
    }
    cout << endl;
    t.print();
    puts("");
    a0.print();
    puts("");
    matrix b1 = t*a0;
    matrix b2 = t*t*a0;
    //b1.print();
    b2.print();

    (t*t*t*t*t*a0).print();
     */
    /*
    for (int i = 950 ; i <= 1000 ; i ++) {
        matrix tn = binpow(t, i - 41);
        tn = tn * a0;
        if (calc(i) != tn.data[0][0])
            cout << "Error " << i << endl;
    }
    */
    if (n <= 41) {
        cout << calc(n) << endl;
        return 0;
    }
    matrix tn = binpow(t, n - 41);
    tn = tn * a0;
    cout << tn.data[0][0] << endl;
    
    
    
    return 0;
}









