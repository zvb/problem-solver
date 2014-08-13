#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;

int n, c, k;
double dp[N][N];
int er[N];

void solve() {
    scanf("%d%d%d", &n, &c, &k);
    for (int i = 0 ; i < N ; i ++) {
        for (int j = 0 ; j < N ; j ++)
            dp[i][j] = 0.0;
        er[i] = 0;
    }
    dp[0][1] = 1.0;
    for (int i = 0 ; i < k ; i ++) { // round
        for (int j = 0 ; j < c; j ++) { // residue
            dp[i + 1][j] += .5*dp[i][j];
            for (int l = 0 ; l < c ; l ++) {
                int r = (j*l)%c;
                dp[i+1][r] += dp[i][j] / (2*c);
            }
        }
    }
    for (int i = 0 ; i < k ; i ++) {
        int l, r;
        scanf("%d%d", &l, &r);
        for (int j = l ; j <= r ; j ++)
            er[j] ++;
    }
    /*
    puts("DEBUG");
    for (int i = 0 ; i <= k ; i ++) {
        for (int j = 0 ; j < c ; j ++)
            printf("%.2lf ", dp[i][j]);
        puts("");
    }
    puts("");
    for (int i = 1 ; i <= n ; i ++)
        cout << er[i] << ' ';
    cout << endl;*/
    double res = 0.0;
    for (int i = 1 ; i <= n ; i ++) {
        int m = er[i];
        for (int j = 0 ; j < c ; j ++)
            res += dp[m][j] * j;
    }
    printf("%.12lf\n", res);
    //puts("");
    
}


int main() {
    int t;
    scanf("%d", &t);
    while (t --)
        solve();
    
    return 0;
}