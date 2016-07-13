#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

#define filename ""

const int N = (int)1e5 + 100;

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int ans = 0;
    while (n > 0 && m > 0 && n + m >= 3) {
        if (n > m) {
            
            n -= 2;
            m --;
        } else {
            n --;
            m -= 2;
            
        }
        ans ++;
    }
    cout << ans << endl;
    return 0;
}