#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int p = (int)2e9 + 9;
//const int p = 3;
const int N = (int)2e5 + 100;

int n, w, a[N], b[N], d[N], l[N];

int z[N*2], s[2*N];

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 0 ; i < n ; i ++) {
        scanf("%d", &a[i]);
        if (i) {
            d[i - 1] = a[i] - a[i-1];
        }
    }
    if (w == 1) {
        cout << n << endl;
        return 0;
    }
    //cout << endl;
    for (int i = 0 ; i < w; i ++) {
        scanf("%d", &b[i]);
        if (i) {
            l[i-1] =  b[i] - b[i-1];
        }
    }
    //cout << "x = " << x << endl;
    int len = 0;
    for (int i = 0 ; i + 1 < w ; i ++, len ++)
        s[len] = l[i];
    
    s[len ++] = p;
    
    for (int i = 0 ; i + 1 < n ; i ++, len ++)
        s[len] = d[i];


    z[0] = 0;
    /*
    for (int i = 0 ; i < len ; i ++)
        cout << s[i] << ' ' ; cout << endl;
    */
    for (int i = 1 ; i < len ; i ++) {
        int j = z[i-1];
        while (j > 0 && s[j] != s[i])
            j = z[j - 1];
        if (s[j] == s[i])
            j ++;
        z[i] = j;
        //cout << z[i] << ' ';
    }
    //cout << endl;
    int ans = 0;
    for (int i = 0 ; i < len ; i ++) {
        if (z[i] == w - 1)
            ans ++;
    }
    printf("%d\n", ans);
    
    
    
    return 0;
}