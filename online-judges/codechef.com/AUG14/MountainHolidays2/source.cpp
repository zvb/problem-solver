#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

const int N = 1000100, EMPTY = 0, mod = 1000000009, OFF = 5*N;
int h[N], d[N];
int mp[10*N];
void solve() {
    int n;
    cin >> n;
    
    for (int i = 0 ; i < n ; i++) {
        d[i] = 0;
        cin >> h[i];
        if (i > 0) {
            d[i] = h[i] - h[i-1];
            mp[d[i] + OFF] = 0;
        }
    }
    
    mp[EMPTY] = 1;
    int total = 1;
    for (int i = 1 ; i < n ; i++) {
        int delta = total - mp[d[i] + OFF];
        
        if (delta < 0) delta += mod;
        
        mp[d[i] + OFF] = total;
        total += delta; if (total >= mod) total -= mod;
    }
    if (total == 0) total = mod;
    cout << total - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}