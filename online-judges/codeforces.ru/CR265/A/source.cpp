#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
int n, m;
string s;
bool dp[1111];
string d[1111];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    cin >> s;
    for (int i = 0 ; i < n ; i ++) {
        if (s[i] == 'a' + m - 1) {
            if (i == 0 || dp[i-1] == 0)
                dp[i] = 0;
            else {
                bool good = 0;
                for (char j = 'a' ; j < 'a' + m ; j ++) {
                    if (d[i-1][i-1] != j && (i == 1 || d[i-1][i-2] != j)) {
                        dp[i] = 1;
                        d[i] = d[i-1] + j;
                        good = 1;
                        break;
                    }
                }
                if (!good)
                    dp[i] = 0;
            }
        } else {
            if (i == 0) {
                dp[i] = 1;
                d[i] = s[i] + 1;
                continue;
            }
            bool good = 0;
            for (char j = s[i] + 1 ; j < 'a' + m ; j ++) {
                if (s[i-1] != j && (i == 1 || s[i-2] != j)) {
                    dp[i] = 1;
                    d[i] = s.substr(0, i) + j;
                    good = 1;
                    break;
                }
            }
            if (!good) {
                if (dp[i-1] == 0) {
                    dp[i] = 0;
                    continue;
                }
                for (char j = 'a' ; j < 'a' + m ; j ++) {
                    if (d[i-1][i-1] != j && (i == 1 || d[i-1][i-2] != j)) {
                        dp[i] = 1;
                        d[i] = d[i-1] + j;
                        good = 1;
                        break;
                    }
                }
                if (!good)
                    dp[i] = 0;

            }
            
        }
    }
    if (dp[n-1]) {
        cout << d[n-1] << endl;
    } else {
        cout << "NO\n";
    }
    return 0;
}