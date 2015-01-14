#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 111, INF = 1 << 30;

struct node {
    int i, j, step;
    node() {}
    node(int _i, int _j, int _step): i(_i), j(_j), step(_step) {}
};

int t, n, m;
char g[N][N];
int d[N][N][4], c[N][N][4], v[N][N][4];
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
node q[4*N*N];
int qh, qt;

string s = ">v<^";
int si, sj, gi, gj;

int main() {
    
    scanf("%d\n", &t);
    for (int tt = 1 ; tt <= t ; tt ++) {
        scanf("%d%d\n", &n, &m);
        for (int i = 1 ; i <= n ; i ++) {
            gets(g[i] + 1);
        }

        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1; j <= m; j ++) {
                for (int k = 0 ; k < 4 ; k++) {
                    if (g[i][j] == '.' || g[i][j] == 'S' || g[i][j] == 'G')
                        c[i][j][k] = 1;
                    else
                        c[i][j][k] = 0;
                    d[i][j][k] = INF;
                    v[i][j][k] = 0;
                }
                if (g[i][j] == 'S')
                    si = i, sj = j;
                else if (g[i][j] == 'G')
                    gi = i, gj = j;
            }
        }
        
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                int idx = s.find(g[i][j]);
                if (idx < s.length()) {
                    //cerr << "i = " << i << " j = " << j << " idx = " << idx << endl;
                    for (int k = idx, r = 0; r < 4; r++, k = (k+1)%4) {
                        //cerr << "k = " << k << " r = " << r << endl;
                        for (int ii = i, jj = j; ii >= 1 && ii <= n && jj >= 1 && jj <= m; ii += di[k], jj += dj[k]) {
                            //cerr << "ii = " << ii << " jj = " << jj << endl;
                            if (g[ii][jj] == '.' || g[ii][jj] == 'S' || g[ii][jj] == 'G') {
                                c[ii][jj][r] = 0;
                            } else if (ii != i || jj != j)
                                break;
                        }
                    }
                }
            }
        }
        qh = 0; qt = 0;
        
        q[qh ++] = node(si, sj, 0);
        v[si][sj][0] = 1;
        d[si][sj][0] = 0;
        
        
        //debug
        /*
        for (int k = 0 ; k < 4 ; k ++) {
            for (int i = 1 ; i <= n ; i++) {
                for (int j = 1 ; j <= m ; j ++) {
                    printf("%d ", c[i][j][k]);
                }
                puts("");
            }
            puts("");
        }
        */
        
        while (qt < qh) {
            node cur = q[qt ++];
            int nextstep = cur.step + 1;

            for (int k = 0 ; k < 4 ; k ++) {
                int ii = cur.i + di[k], jj = cur.j + dj[k];
                if (ii >= 1 && ii <= n && jj >= 1 && jj <= m && !v[ii][jj][nextstep%4]
                    && c[ii][jj][nextstep%4])
                {
                    v[ii][jj][nextstep%4] = 1;
                    q[qh ++] = node(ii, jj, nextstep);
                    d[ii][jj][nextstep%4] = nextstep;
                }
            }
        }
        int ans = INF;
        for (int k = 0 ;k < 4 ;k ++)
            ans = min(ans, d[gi][gj][k]);
        if (ans < INF) {
            printf("Case #%d: %d\n", tt, ans);
        } else {
            printf("Case #%d: impossible\n", tt);
        }
    }
    
    return 0;
}
