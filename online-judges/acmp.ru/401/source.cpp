#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

//==================BEGIN=====================
const int base = (int)1e9;
struct BigInt {
    vector<int> a;
    BigInt() {}
    BigInt(long long L) {
        while (L > 0) {
            a.push_back(L % base);
            L /= base;
        }
    }
    BigInt operator+(const BigInt o) {
        BigInt res;
        long long cur = 0 , car = 0;
        for (int i = 0 ; i < max(a.size(), o.a.size()) || car > 0 ; i ++) {
            cur = car + (i < a.size() ? a[i] : 0) + (i < o.a.size() ? o.a[i] : 0);
            res.a.push_back(cur % base);
            car = cur / base;
        }
        return res;
    }
    BigInt operator*(const BigInt o) {
        BigInt res; res.a.resize(a.size() + o.a.size() + 1);
        for (int i = 0 ; i < a.size() ; i ++) {
            long long car = 0;
            for (int j = 0 ; j < o.a.size() || car > 0; j ++) {
                long long cur = res.a[i+j] + car + 1ll*a[i]*(j < o.a.size() ? o.a[j] : 0);
                res.a[i+j] = cur % base;
                car = cur / base;
            }
        }
        while (res.a.size() > 0 && res.a.back() == 0)
            res.a.pop_back();
        return res;
    }
    void print() {
        if (a.size() == 0) {
            printf("0");
            return;
        }
        for (int i = a.size() - 1 ; i >= 0 ; i --) {
            if (i == a.size() - 1)
                printf("%d", a[i]);
            else
                printf("%09d", a[i]);
        }
    }
};
//==================END=====================

BigInt C[100][100];



int A, B, N;

BigInt f(int k, int a) {
    if (k > a) return 0;
    if (k == 0) return a == 0;
    return C[N][k] * C[a-1][k-1];
}



int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &N, &A, &B);
    for (int i = 0 ; i <= 60 ; i ++) {
        C[i][0] = BigInt(1);
        for (int j = 1 ; j <= i ; j ++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    //cout << "here" << endl;
    /*
    for (int a = 0 ; a <= A ; a ++) {
        for (int b = 0 ; b <= B ; b ++) {
            for (int l = 0 ; l <= min(N, b) ; l ++) {
                for (int k = 0 ; k <= min(N, A) ; k ++) {
                    res += f(k, a)*f(l, b);
                }
            }
        }
    }
     */

    BigInt res(0);
    
    for (int a = 0 ; a <= A; a ++) {
        for (int b = 0 ; b <= B ; b ++) {
            BigInt tmp = C[a+N-1][N-1] * C[b+N-1][N-1];
            res = res + tmp;
            //cout << "here" << endl;
        }
    }
    res.print(); puts("");
    /*

    for (int k = 0 ; k <= N ; k ++) {
        for (int l = 0 ; l <= N ; l ++) {
            for (int a = k ; a <= A ; a ++) {
                for (int b = l ; b <= B ; b ++) {
                    //cout << "(l, k, a, b) = ("
                    //<< l << ", " << k << ", " << a << ", " << b << ") -> ";
                    //cout << f(k, a) * f(l, b) << endl;
                    //res.print(); puts("");
                    BigInt tmp(f(k, a) * f(l, b));
                    res = res + tmp;

                    //assert(res <= largest && res >= 0);
                }
            }
        }
    }

    res.print();
    puts("");
    */
    
    return 0;
}