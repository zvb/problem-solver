#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1010, base = (int)1e9;
int n, m;

struct big {
    vector<int> a;
    big operator+(const big& r) {
        big res;
        res.a.resize(max(r.a.size(), a.size()) + 1);
        long long car = 0;
        for (int i = 0 ; i < res.a.size() ; i ++) {
            long long cur = 0;
            if (i < a.size()) cur += a[i];
            if (i < r.a.size()) cur += r.a[i];
            cur += car;
            res.a[i] = cur % base;
            car = cur / base;
        }
        while (res.a.size() > 0 && res.a.back() == 0)
            res.a.pop_back();
        return res;
    }
    big operator*(const big& r) {
        big res;
        res.a.resize(r.a.size() + a.size() + 1);
        long long car = 0;
        for (int i = 0 ; i < a.size() ; i ++) {
            car = 0;
            for (int j = 0 ; j < r.a.size() || car > 0; j ++) {
                long long cur = res.a[i+j] + 1ll * a[i] * (j < r.a.size() ? r.a[j] : 0) + car;
                res.a[i+j] = cur % base;
                car = cur / base;
            }
        }
        while (res.a.size() > 0 && res.a.back() == 0)
            res.a.pop_back();
        return res;
    }
    void print() {
        if (a.size() == 0)
            printf("0");
        else {
            for (int i = a.size() - 1 ; i >= 0 ; i --) {
                if (i == a.size() - 1)
                    printf("%d", a[i]);
                else
                    printf("%09d", a[i]);
            }
        }
    }
};
big dp[N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    dp[1].a.push_back(1);
    big a, b, c;
    a.a.push_back(0);
    b.a.push_back(0); c.a.push_back(0);
    for (int j = 1 ; j <= m ; j ++) {
        for (int i = 1 ; i <= n ; i ++) {
            if (i == 1 && j == 1) continue;
            a.a[0] = j * (j + 1) / 2 * i;
            dp[i] = dp[i-1] + a;
        }
    }
    dp[n].print();
    puts("");
    return 0;
}