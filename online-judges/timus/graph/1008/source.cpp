#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

int n, m;
int g[15][15], u[15][15];
int xs = -1, ys = -1;

pair<int, int> q[1000];
int qh = 0, qt = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'R', 'T', 'L', 'B'};
int inv[255];

int main() {
    
    for (int k = 0 ; k < 4 ; k ++)
        inv[dir[k]] = k;
    
    scanf("%d", &n);
    if (cin.peek() == '\n') {
        for (int i = 0 ; i < n ; i ++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (xs == -1)
                xs = x, ys = y;
            g[x][y] = 1;
        }
        printf("%d %d\n", xs, ys);
        q[qh ++] = make_pair(xs, ys);
        u[xs][ys] = 1;
        while (qh != qt) {
            int cx = q[qt].first, cy = q[qt].second;
            qt ++;
            for (int k = 0 ; k < 4 ; k ++) {
                if ( g[cx + dx[k]][cy + dy[k]] && !u[cx + dx[k]][cy+dy[k]] ) {
                    u[cx + dx[k]][cy+dy[k]] = 1;
                    printf("%c", dir[k]);
                    q[qh ++] = make_pair(cx + dx[k], cy + dy[k]);
                }
            }
            if (qh != qt)
                puts(",");
            else
                puts(".");
        }
    } else {
        string s;
        xs = n;
        scanf("%d\n", &ys);
        q[qh ++] = make_pair(xs, ys);
        int num = 0;
        do {
            getline(cin, s);
            int cx = q[qt].first, cy = q[qt].second;
            //cout << "cx, cy = " << cx << ',' << cy << " " << s << endl;
            g[cx][cy] = 1;
            qt ++;
            
            for (int j = 0 ; j + 1 < s.length() ; j ++) {
                int k = inv[s[j]];
                g[cx + dx[k]][cy + dy[k]] = 1;
                q[qh ++] = make_pair(cx + dx[k], cy + dy[k]);
            }
            
            num ++;
        } while (s.back() != '.');
        printf("%d\n", num);
        for (int i = 0 ; i <= 10 ; i ++) {
            for (int j = 0 ; j <= 10 ; j ++) {
                if (g[i][j])
                    printf("%d %d\n", i, j);
            }
        }
    }
    
    
    
    
    
    
    
    return 0;
}
