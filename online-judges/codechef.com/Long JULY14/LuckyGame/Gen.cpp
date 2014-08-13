#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

const int N = 1010;

int c = 100;

int main() {
    //ios_base::sync_with_stdio(false);
    int T = c * c;
    int n = 1, m = 1;
    cout << T << endl;
    for (int t = 1 ; t <= T ; t ++) {
        cout << n << ' ' << m << endl;
        for (int i = 1 ; i < n ; i ++)
            cout << i << ' ';
        cout << 0 << endl;
        cout << endl;
        m ++;
        if (m == c + 1) {
            m = 1;
            n ++;
        }
    }
 
    
    return 0;
}