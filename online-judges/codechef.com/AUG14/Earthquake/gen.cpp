#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    srand( clock() * (time(0)%7 + 1) );
    int n = 25;
    cout << n << endl;
    for (int i = 0 ; i < n ; i ++) {
        int len = rand()%4 + 1;
        int num = 0;
        for (int i = 0 ; i < len ; i ++)
            num = (num * 10 + rand()%10);
        cout << num << ' ';
    }
    cout << endl;
    int m = 25;
    cout << m << endl;
    for (int i = 0 ; i < m ; i ++) {
        if (rand() & 1) {
            int l = rand()%n, r = rand()%n;
            if (l > r) swap(l, r);
            cout << 1 << ' ' << l << ' ' << r << '\n';
        } else {
            int l = rand()%n, r = rand()%n;
            if (l > r) swap(l, r);
            int f = rand()%60;
            cout << 0 << ' ' << l << ' ' << r << ' ' << f << '\n';
        }
    }
    return 0;
}