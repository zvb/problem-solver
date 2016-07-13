#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>

using namespace std;

const int N = 303, mod = int(1e9)+7;


int binPow(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1) {
            res = (1ll * a * res) % mod;
        }
        a = (1ll*a*a)%mod;
        p >>= 1;
    }
    return res;
}

int mp[N][N*N], u[N][N*N];

int n, a[N], s;

int rec(int from, int s) {
    if (u[from][s])
        return mp[from][s];
    u[from][s] = 1;
    
    //int lowest = *l.begin();
    if (from > n || s <= a[from]) {
        int res = binPow(s, n);
        mp[from][s] = res;
        return res;
    }
    //vector<int> go = l;
    //vector<int> go2 = l;
    
    //l.erase(l.begin());
    //l.insert(S);
    
    int A = rec(from + 1, s);
    
    //l.erase(l.find(S));
    //l.insert(S - lowest);
    
    int B = rec(from + 1, s - a[from]);

    int res = (A - B + mod) % mod;
    mp[from][s] = res;
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &s);
    
    sort(a+1, a+n+1);
    
    cout << rec(1, s) << endl;
    
    return 0;
}