#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;

int n, a[222][222], d[222][222], qh, qt, bad[222][222], val[222][222];
pair<int, int> q[511111], par[222][222];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
bool ok(int X, int Y) {
    return X <= n && X >= 1 && Y <= n && Y >= 1;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i ++)
        for (int j = 1 ; j <= n ; j ++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] > 0) {
                val[i][j] = a[i][j];
                q[qh ++] = make_pair(i, j);
                par[i][j] = make_pair(i, j);
                d[i][j] = 0;
            } else
                d[i][j] = inf;
        }
    while (qt < qh) {
        int x = q[qt].first, y = q[qt].second; qt ++;
        cout << "at " << x << ' ' << y << endl;
        for (int k = 0 ; k < 4 ; k ++) {
            int ii = x + dx[k], jj = y + dy[k];
            if (!ok(ii, jj)) {
                continue;
            }
            if (d[ii][jj] > d[x][y] + 1) {
                d[ii][jj] = d[x][y] + 1;
                a[ii][jj] = a[x][y];
                par[ii][jj] = par[x][y];
                q[qh ++] = make_pair(ii, jj);
                cout << "added " << ii << ' ' << jj << endl;
            }
            else if (d[ii][jj] == d[x][y] + 1 ) {
                if (par[ii][jj] != par[x][y])
                    bad[ii][jj] = 1;
            }
            
        }
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= n ; j ++) {
            if (!bad[i][j])
                printf("%d ", a[i][j]);
            else
                printf("0 ");
        }
        puts("");
    }
    
    return 0;
}