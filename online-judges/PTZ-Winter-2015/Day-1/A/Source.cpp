#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <map>

using namespace std;

typedef unsigned int myint;
//typedef long long myint;

const myint phi = 1ll << 31;
const myint x = 1 << 16;
const myint z = (1ll << 32) - 1;
const long long p32 = 1ll << 32;



myint binPow(myint x, long long p) {
    myint res = 1;
    while (p) {
        if (p & 1)
            res *= x;
        x = x * x;
        p >>= 1;
    }
    return res;
}

myint inverse(myint x) {
    return binPow(x, phi - 1);
}

myint inv[1 << 16];

myint fac[1 << 16];
myint pre[1 << 16];

myint sumInv = 0;
myint f[1 << 16];

void precalc() {
    for (myint i = 1 ; i < (1 << 16) ; i += 2)
    {
        inv[i] = inverse(i);
        sumInv += inv[i];
        if (i == 1)
            fac[i] = 1;
        else
            fac[i] = fac[i-2]*i;
    }
}

myint factOddSmall(long long n) {
    //cout << "factOddSmall " << n << endl;
    myint y = sumInv;
    //cout << "Sum inv = " << sumInv << endl;
    assert (n < (1ll << 32));
    myint s = (myint)(n >> 16);
    myint res = 1;
    //cout << " s = " << s  << " y = " << y <<  ' ' << n << ' ' << x << endl;
    
    for (myint i = 0 ; i < s; i ++) {
        res *= (fac[x-1] + i*x*y);
        //cout << "i = " << i << endl;
    }
    //cout << s*x+1 << endl;
    for (long long i = 1ll * s * x + 1; i <= n ; i += 2) {
        res *= (myint)(i);
    }
    //cout << " s = " << s  << " y = " << y << ' ' << n << endl;
    return res;
}

myint factorialOddLarge(long long n) {
    //cout << "here " << n << endl;

    myint s = (myint)(n / p32);
    myint kusok = n - (n/s)*p32 ;
    //cout << "here " << s << endl;
    myint zf = factOddSmall( z );

    myint zfPowS = binPow(zf, s) * factOddSmall(kusok);

    return zfPowS;
}



myint factorialOdd(long long n) {
    //cout << "FactODD " << n << endl;
    
    if (n <= z)
        return factOddSmall(n);
    return factorialOddLarge(n);
}




myint factX(long long n) {
    //cout << "factX n = " << n << endl;

    if (n <= 1) return 1;
    return factorialOdd(n) * factX(n/2);
}

long long twos(long long n) {
    long long res = 0;
    for (long long i = 2; i <= n ; i <<= 1)
        res += n/i;
    return res;
}



myint getC(long long n, long long k) {
    long long tn = twos(n), tk = twos(k), tnk = twos(n-k);
    //cout << tn << ' ' << tk << ' ' << tnk << '\n';
    long long diff = tn - tk - tnk;
    if (diff >= 32) {
        return 0;
    }
    //cout << diff << endl;
    //cout << factX(n) << ' ' << factX(n-k) << ' ' << factX(k) << endl;
    
    return (binPow(2, diff) * factX(n) * inverse(factX(n-k)) * inverse(factX(k))) & z ;
}

int main() {
    //srand(time(0) + clock());
    precalc();
//    prepStupid();
    long long n, k;
    /*
    while (cin >> n)
        cout << factX(n) << endl;
    */

    cin >> n >> k;
    
    cout << getC(n, k) << endl;
    /*
    while (true ) {
        n = rand()%1000;
        k = rand()%1000;
        if (n < k) swap(n, k);
        if (stupid(n, k) != getC(n, k)) {
            cout << "error " << n << ' ' << k << endl;
            cout << "actual " << getC(n, k) << " expected " << stupid(n, k) << endl;
            return 0;
        }
            
    }
    */
    return 0;
}