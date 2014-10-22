#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1600;

int n, m;
char g[N][N]; int d[N][N];

pair<int, int> start(-1, -1), q[N*N];
int qh, qt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> s(-1, -1);
int mx = 0;

int main() {
    scanf("%d%d ", &n, &m);
    swap(n, m);
    for (int i = 1 ; i <= n ; i ++) {
        gets(g[i] + 1);
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j ++) {
            if (g[i][j] == '.') {
                if (start.first == -1)
                    start = make_pair(i, j);
            }
            d[i][j] = -1;
        }
    }
    qh = qt = 0;
    d[start.first][start.second] = 0;
    q[qh ++] = start;
    
    
    
    while (qt < qh) {
        int curx = q[qt].first, cury = q[qt].second;
        //cout << "cur x, y = " << curx << ' ' << cury << endl;
        qt ++;
        for (int k = 0 ; k < 4 ; k ++) {
            int tox = dx[k] + curx, toy = dy[k] + cury;
            if (d[tox][toy] == -1 && g[tox][toy] == '.') {
                d[tox][toy] = d[curx][cury] + 1;
                q[qh ++] = make_pair(tox, toy);
                if (d[tox][toy] > mx) {
                    mx = d[tox][toy];
                    s = make_pair(tox, toy);
                }
            }
        }
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j++) {
            d[i][j] = -1;
        }
    }
    qh = qt = 0;
    d[s.first][s.second] = 0;
    q[qh ++] = s;
    mx = 0;
    while (qt < qh) {
        int curx = q[qt].first, cury = q[qt].second;
        qt ++;
        for (int k = 0 ; k < 4 ; k ++) {
            int tox = dx[k] + curx, toy = dy[k] + cury;
            if (d[tox][toy] == -1 && g[tox][toy] == '.') {
                d[tox][toy] = d[curx][cury] + 1;
                q[qh ++] = make_pair(tox, toy);
                if (d[tox][toy] > mx) {
                    mx = d[tox][toy];
                }
            }
        }
    }
    printf("%d\n", mx);
    
    return 0;
}
