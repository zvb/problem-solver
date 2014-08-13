#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int win[35][15], found[35][15];
int mi[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int rec(int d, int m) {
    if (d == 31 && m == 12) return 1;
    if (found[d][m]) return win[d][m];
    found[d][m] = 1;
    int res = 0;
    if (m + 1 <= 12 && d <= mi[m+1])
        res |= !rec(d, m + 1);
    if (m + 2 <= 12 && d <= mi[m+2])
        res |= !rec(d, m + 2);
    if (d + 1 <= mi[m])
        res |= !rec(d + 1, m);
    if (d + 2 <= mi[m])
        res |= !rec(d + 2, m);
    return win[d][m] = res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int d, m;
    scanf("%d%d", &d, &m);
    if (rec(d, m))
        cout << 1 << endl;
    else
        cout << 2 << endl;
 
    
    return 0;
}