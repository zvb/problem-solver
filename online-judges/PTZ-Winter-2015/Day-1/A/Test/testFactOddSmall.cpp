#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

const int lim = (int)1e7;

bool sieve[lim];

vector<unsigned int> primes;

long long getCount(long long n, int p) {
    long long ans = 0;
    long long pp = p;
    while (pp <= n) {
        ans += n/pp;
        pp *= p;
    }
    return ans;
}

int main() {
    sieve[1] = 1;
    for (int i = 2 ; i < lim ; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = 2 * i ; j < lim ; j += i)
                sieve[j] = 1;
        }
    }
    
    int t;
    cin >> t;
    while (t --) {
        long long n;
        cin >> n;
        unsigned int res = 1;
        for (int i = 1 ; i < primes.size() ; i++) {
            int p = primes[i];
            long long cnt = getCount(n, p);
            if (cnt == 0)
                break;
            //cout << "p = " << p << ' ' << cnt << endl;
            while (cnt --) {
                res *= (unsigned int)p;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}