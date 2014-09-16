#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = (int)1e5 + 10;


int n, m, d[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++)
        cin >> d[i];
    int diff = 0;
    while (m --) {
        char t; int v;
        cin >> t >> v;
        if (t == 'C') {
            diff += v;
        } else if (t == 'A') {
            diff -= v;
        } else {
            v --;
            cout << d[(v + diff + n) % n];
        }
        diff %= n;
    }
    return 0;
}