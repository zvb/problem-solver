#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <map>

using namespace std;

typedef unsigned int uint;

const int phi = 1<<31;
const uint x = 1 << 16;
const uint z = -1;



uint binPow(uint x, long long p) {
    uint res = 1;
    while (p) {
        if (p & 1)
            res *= x;
        x = x * x;
        p >>= 1;
    }
    return res;
}

uint inverse(uint x) {
    return binPow(x, phi - 1);
}

uint inv[1 << 16];

uint fac[1 << 16];
uint pre[1 << 16];

uint sumInv = 0;
uint f[1 << 16];

void precalc() {
    for (uint i = 1 ; i < (1 << 16) ; i += 2)
    {
        inv[i] = inverse(i);
        sumInv += inv[i];
        if (i == 1)
            fac[i] = 1;
        else
            fac[i] = fac[i-2]*i;
    }
}

uint factOddSmall(long long n) {
    //cout << "factOddSmall " << n << endl;
    uint y = sumInv;
    //cout << "Sum inv = " << sumInv << endl;
    assert (n < (1ll << 32));
    uint s = (uint)(n >> 16);
    uint res = 1;
    //cout << " s = " << s  << " y = " << y <<  ' ' << n << ' ' << x << endl;
    
    for (uint i = 0 ; i < s; i ++) {
        res *= (fac[x-1] + i*x*y);
        //cout << "i = " << i << endl;
    }
    //cout << s*x+1 << endl;
    for (long long i = 1ll * s * x + 1; i <= n ; i += 2) {
        res *= (uint)(i);
    }
    //cout << " s = " << s  << " y = " << y << ' ' << n << endl;
    return res;
}

uint factorialOddLarge(long long n) {
    uint s = (uint)(n >> 32);
    uint kusok = n % s;
    //cout << "here " << s << endl;
    uint zf = factOddSmall( z );

    uint zfPowS = binPow(zf, s) * factOddSmall(kusok);

    return zfPowS;
}

map<long long, uint> memoFO;

uint factorialOdd(long long n) {
    //cout << "FactODD " << n << endl;
    if (memoFO.find(n) != memoFO.end())
        return memoFO[n];
    if (n <= z)
        return memoFO[n] = factOddSmall(n);
    return memoFO[n] = factorialOddLarge(n);
}


map<long long, uint> memoFX;

uint factX(long long n) {
    //cout << "factX n = " << n << endl;
    if (memoFX.find(n) != memoFX.end())
        return memoFX[n];
    if (n <= 1) return 1;
    return memoFX[n] = factorialOdd(n) * factX(n/2);
}

long long twos(long long n) {
    long long res = 0;
    for (long long i = 2; i <= n ; i <<= 1)
        res += n/i;
    return res;
}

int main() {
    precalc();
    long long n, k;
    /*
    while (cin >> n)
        cout << factX(n) << endl;
    */

    cin >> n >> k;
    long long tn = twos(n), tk = twos(k), tnk = twos(n-k);
    //cout << tn << ' ' << tk << ' ' << tnk << '\n';
    long long diff = tn - tk - tnk;
    if (diff >= 32) {
        cout << 0 << endl;
        return 0;
    }
    //cout << diff << endl;
    //cout << factX(n) << ' ' << factX(n-k) << ' ' << factX(k) << endl;
    
    cout << binPow(2, diff) * factX(n) * inverse(factX(n-k)) * inverse(factX(k)) << endl;
    
    return 0;
}