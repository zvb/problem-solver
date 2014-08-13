#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(clock() * (time(0) % 7 + 1));
    int n = 10, m = 10;
    cout << n << ' ' << m << endl;
    for (int i = 0 ; i < n ; i ++) {
        cout << rand() % 10 + 1 << ' ';
    }
    cout << endl;
    
    for (int i = 0 ; i < m ; i ++) {
        int l = rand()%n + 1, r = rand()%n + 1;
        if (l > r) swap(l, r);
        if (rand() & 1) {
            cout << 1 << " " << l << ' ' << r << endl;
        } else {
            cout << 2 << " " << l << ' ' << r << endl;
        }
    }
    return 0;
}