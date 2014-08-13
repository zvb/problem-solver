#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 100;

int n, d, a[N], b[N], c[N];
long long x;

long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
int w[N];
int v[N], vn = 0;

int main() {
    cin >> n >> d >> x;
    initAB();
    for (int i = 0 ; i < n ; i ++)
        w[a[i]] = i;
    
    for (int i = 0 ; i < n ; i ++)
        if (b[i])
            v[vn ++] = i;
    
    int l = 500;
    int u = n - l;
    if (u < 0) u = 1;
    for (int i = n - 1 ; i >= 0 ; i --) {

        for (int r = n ; r >= u ; r --) {
            if (i - w[r] >= 0 && b[i - w[r]]) {
                c[i] = r;
                break;
            }
        }
        if (!c[i]) {
            for (int j = 0 ; j < vn ; j ++)
                if (i >= v[j] && c[i] < a[i - v[j]])
                    c[i] = a[i - v[j]];
        }
    }
    for (int i = 0 ; i < n ; i ++)
        printf("%d\n", c[i]);
    
    return 0;
}