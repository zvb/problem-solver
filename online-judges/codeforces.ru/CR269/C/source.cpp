#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

const int N = 2000010;

set<int> s;

void f(long long n, int time) {
    if (n < 5) return;
    for (int k = 1 ; k <= N ; k ++) {
        if ( (n + k) % 3 == 0) {
            long long m = (n + k) / 3;
            m -= (1ll*k)*(k+1)/2;
            if (m >= k) {
                if (time == 1) {
                    s.insert(k);
                    cout << k << endl;
                }
                else {
                    s.insert(k + 1);
                    cout << k + 1 << endl;
                }
                
            }
        }
    }
}

int main() {
    long long n;
    cin >> n ;
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    f(n,1);
    f(n - 2,2);
    cout << s.size() << endl;
    
    return 0;
}