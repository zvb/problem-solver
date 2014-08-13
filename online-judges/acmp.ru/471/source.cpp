#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include <vector>
#include <algorithm>
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

BigInt dp[10][105]; int n;
int mv[10][3] = {
    {4, 6, -1},
{8, 6, -1},
{7, 9, -1},
{4, 8, -1},
{3, 9, 0},
{-1, -1, -1},
{1, 7, 0},
{2, 6, -1},
{1, 3, -1},
    {2, 4, -1}
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0 ; i < 10 ; i++)
        if (i != 0 && i != 8)
            dp[i][1] = BigInt(1);
    for (int i = 1 ; i <= n ; i++) {
        for (int d = 0 ; d < 10 ; d ++) {
            for (int j = 0 ; j < 3 ; j ++) {
                if (mv[d][j] != -1) {
                    dp[mv[d][j]][i+1] = dp[mv[d][j]][i+1] + dp[d][i];
                }
            }
        }
    }
    BigInt res;
    for (int i = 0 ; i < 10 ; i ++)
        res = res + dp[i][n];
    res.print();
    puts("");
    
    return 0;
}