#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;


int n, m, a[100][100];
bool check(int ii, int jj, int s) {
    for (int i = ii ; i <= ii + s - 1 ; i++) {
        for (int j = jj ; j <= jj + s - 1 ; j ++) {
            if (i >= ii + 2) {
                if (a[i][j] - a[i-1][j] != a[i-1][j] - a[i-2][j])
                    return 0;
            }
            if (j >= jj + 2) {
                if (a[i][j] - a[i][j-1] != a[i][j-1] - a[i][j-2])
                    return 0;
            }
        }
    }
    for (int i = ii ; i <= ii + s - 1 ; i++) {
        for (int j = jj ; j <= jj + s - 1 ; j ++) {
            if (i >= ii + 1 && j >= jj + 1) {
                if (a[i][j] - a[i-1][j] != a[i][j-1] - a[i-1][j-1])
                    return 0;
                if (a[i][j] - a[i][j-1] != a[i-1][j] - a[i-1][j-1])
                    return 0;
            }
        }
    }
    int dh = a[ii][jj] - a[ii+1][jj];
    int dv = a[ii][jj] - a[ii][jj+1];
    if (dh == 0 || dv == 0)
        return 1;
    if (dh == dv || dh == -dv)
        return 1;
    return 0;
}





int main() {
    while (1) {
        scanf("%d%d", &n, &m);
        if (!n && !m)
            break;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                scanf("%d", &a[i][j]);
            }
        }
        int res = 1;
        for (int is = 1 ; is <= n ; is ++) {
            for (int js = 1 ; js <= m ; js ++) {
                for (int s = 2 ; s - 1 + is <= n && s - 1 + js <= m ; s ++) {
                    if (check(is, js, s)) {
                        if (s > res) {
                            //cerr << is << ' ' << js << ' ' << s << endl;
                            res = s;
                        }
                    }
                }
            }
        }
        printf("%d\n", res*res);
    }
    return 0;
}