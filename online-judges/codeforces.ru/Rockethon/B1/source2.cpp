#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100;

int ans[N];

long long p2[55];

int n;

void enumerate(long long m, int l, int r) {
    //cout << m << ' ' << l << ' ' << r << endl;
    if (m == 0 || l > r)
        return;
    int len = r - l + 1;
    int put = n - len + 1;
    
    if (len == 1) {
        ans[l] = put;
        return;
    }
    //cout << "len = " << len << " put = " << put << endl;
    
    if (p2[len-2] >= m) {
        ans[l] = put;
        enumerate(m, l + 1, r);
    } else {
        ans[r] = put;
        enumerate(m - p2[len-2], l, r - 1);
    }
}



long long  m;


int main() {
    cin  >> n >> m;
    
    p2[0] = 1;
    for (int i = 1 ; i < 55 ; i++)
        p2[i] = p2[i-1] * 2;
    enumerate(m, 1, n);
    
    for (int i = 1 ; i <= n ; i++)
        printf("%d ", ans[i]);
    puts("");
    
    
    return 0;
}