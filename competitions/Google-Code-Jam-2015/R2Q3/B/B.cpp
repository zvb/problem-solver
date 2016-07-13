#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>


using namespace std;


const int N = 111;

int T;
char a[111], l[111];
int n;
int m;
int k;

int cnt[255];
double dp[N][N];

int main() {
    freopen("B-large.in.txt", "r", stdin);
    freopen("B-large.out.txt", "w", stdout);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d",&T);
    for (int t = 1 ; t <= T ; t ++) {
        scanf("%*d%*d%d ", &n);
        memset(cnt, 0, sizeof(cnt));
        scanf("%s ", a + 1);
        k = strlen(a+1);
        for (int i = 1 ; i <= k ; i++) {
            cnt[a[i]] ++;
        }
        scanf("%s ", l + 1);
        m = strlen(l + 1);

        string L(l + 1);
        int overlap = 0;
        for (int i = 1 ; i < L.length() ; i ++) {
            if (L.substr(i, L.length() - i) == L.substr(0, L.length() - i)) {
                overlap = m - i;
                break;
            }
        }
        int take = 0;
        int cur = 0;
        while (cur + m <= n) {
            cur += m - overlap;
            take ++;
        }

        bool ok = 1;
        for (int i = 1 ; i <= m ; i++) {
            if (cnt[l[i]] == 0)
                ok = 0;
        }
        if (!ok)
            take = 0;

        memset(dp, 0, sizeof(dp));
        for (int j = 0 ; j <= n ; j++)
            dp[0][j] = 1.0;
        for (int i = 1 ; i <= m ; i ++) {
            for (int j = 1 ; j <= n ; j ++) {
                dp[i][j] = dp[i-1][j-1] * cnt[l[i]] / k;
                //printf("%.2lf ", dp[i][j]);
            }
            //puts("");
        }
        double E_write = 0.0;
        for (int j = 1 ; j <= n ; j ++) {
            E_write += dp[m][j];
        }
        //cout << "take = " << take << endl;
        printf("Case #%d: %.9lf\n", t, take - E_write);
    }

    
    return 0;
}
