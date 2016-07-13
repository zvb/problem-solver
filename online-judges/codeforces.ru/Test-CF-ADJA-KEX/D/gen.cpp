#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>


using namespace std;


const int N = (int)1e5;

int v[256];

char s[N];

multiset<long long> ms;
int n;

int main() {
    for (int i = 0 ; i < 26 ; i ++) {
        cout << 0 << ' ';
    }
    cout << endl;
    for (int i = 0 ; i < N ; i++)
        putchar('a');
    puts("");
    return 0;
}