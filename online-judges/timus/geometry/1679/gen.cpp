#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;



int main() {
    int seed = 1ll*(time(0)%7 + 1)*clock();
    srand( seed );
    int t = 1000;
    cout << t << endl;
    while (t --) {
        int r = rand()%999 + 1;
        int x1, y1, x2, y2;
        do {
            x1 = rand()%(r + 1), y1 = rand()%(r + 1);
        } while (x1 * x1 + y1 * y1 > r * r);
        
        do {
            x2 = rand()%(r + 1), y2 = rand()%(r + 1);
        } while (x2 * x2 + y2 * y2 > r * r);
        
        cout << r << ' ' << x1 << ' ' << y1 << ' ' <<
            x2 << ' ' << y2 << endl;
    }
    return 0;
}