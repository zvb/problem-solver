#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

const int N = 10;

double dp[N][11111], cum[N][11111];

int l[N], r[N];

int n;

int main() {
    
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i ++) {
        scanf("%d%d", &l[i], &r[i]);
    }
    for (int left = 0 ; left < n ; left ++) {
        double p = 0.0;
        for (int i = 0 ; i <= 10000 ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                if (j == left ) continue;
                if (l[j] < i) continue;
                p += 1.0 * (min(r[j], i) - l[j] + 1) / (r[j] - l[j] + 1);
            }
            dp[left][i] = p * i;
            if (left == 0)
                cum[left][i] = dp[left][i];
            else
                cum[left][i] = cum[left][i-1] + dp[left][i];
        }
       
    }
    double p = 0.0;
    for (int i = 0 ; i < n ; i ++) {
        
        for (int x = l[i] ; x <= r[i]; x ++) {
            p += cum[i][x - 1] * 1.0 / (r[i] - l[i] + 1);
        }
    }
    printf("%.12lf\n", p);
    
    return 0;
}