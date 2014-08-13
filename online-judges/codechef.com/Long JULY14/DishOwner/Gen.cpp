#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(clock()%10000 + rand());
    int T = 1;
    cout << T << endl;
    int n = 5;
    cout << n << endl;
    for (int i = 1 ; i <= n ; i ++) {
        cout << rand()%10 << ' ';
    }
    cout << endl;
    int q = 10;
    cout << q << endl;
    for (int i = 1 ; i <= q ; i ++) {
        if (rand() & 1)
            cout << 0 << ' ' << rand()%n + 1 << ' ' << rand()%n + 1 << endl;
        else
            cout << 1 << ' ' << rand()%n + 1 << endl;
    }
}