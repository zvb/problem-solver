#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
#define N 100
string s;
int ans[N];

int main() {
    getline( cin, s ) ;
    int q;
    cin >> q;

    
    for (int qq = 0 ; qq < q ; qq ++) {
        string a, b;
        cin >> a >> b;
        //cout << a << ' ' << b << endl;
        ans[qq] = 1 << 30;
        for (int i = 0 ; i < s.length() ; i ++) {
            for (int j = 0 ; j < s.length() ; j ++) {
                if (i + a.length() <= s.length() && j + b.length() <= s.length()) {
                    if (s.substr(i, a.length()) == a && s.substr(j, b.length()) == b) {
                        int l = min(i, j);
                        int r = max(i + a.length(), j + b.length());
                        ans[qq] = min(ans[qq], r - l);
                    }
                }
            }
        }
        if (ans[qq] < (1 << 30)) printf("%d\n", ans[qq]);
        else puts("-1");
    }
}