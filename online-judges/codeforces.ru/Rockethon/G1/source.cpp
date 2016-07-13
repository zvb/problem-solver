#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

const int N = 33, K = 222;

int n, k;

int a[N];

double ans = 0.0;

void calc(int d, double p) {
    //cout << "d = " << d << " p = " << p << endl;
    if (d == k) {
        double cnt = 0.0;
        for (int i = 1 ; i <= n ; i ++) {
            //cout << a[i] << ' ' ;
            for (int j = i + 1; j <= n ; j ++) {
                if (a[i] > a[j]) {
                    //cout << "inversion " << i << ' ' << j << endl;
                    cout << i << ' ' << j << ' ' << p << endl;
                    cnt += p;
                }
            }
        }
        //cout << endl;
        ans += cnt;
    } else {
        for (int l = 1 ; l <= n ; l ++) {
            for (int r = l ; r <= n; r ++) {
                for (int t = l ; t <= (r + l)/2 ; t ++)
                    swap(a[t], a[l + r - t]);
                calc(d + 1, p * 2.0 / (n*(n+1)));
                for (int t = l ; t <= (r + l)/2 ; t ++)
                    swap(a[t], a[l + r - t]);
            }
        }
    }
}


int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1 ; i <= n ; i ++) {
        scanf("%d", &a[i]);
    }
    calc(0, 1);
    printf("%.12lf\n", ans);
   
    
    
    return 0;
}