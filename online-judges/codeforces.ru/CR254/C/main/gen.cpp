#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;


int main() {
    srand((clock()%7) * clock());
    int n = 10;
    int m = 16;
    cout << n << ' ' << m << endl;
    for (int i = 0 ; i < m ; i ++) {
        int l = rand()%n + 1, r = rand()%n + 1;
        if (l > r)
            swap(l, r);
        if (rand() & 1) {
            
            cout << "2 " << l << ' ' << r << endl;
        } else {
            int x = rand()%m + 1;
            cout << "1 " << l << ' ' << r << ' ' << x << endl;
        }

    }
    return 0;
}