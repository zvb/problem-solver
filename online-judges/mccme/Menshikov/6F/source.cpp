#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 50
using namespace std;
int n, g[N][N];
char str[50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    scanf("%d ", &n);
    for (int i = 1 ; i <= n ; i ++) {
        gets(str);
        for (int j = 0 ; j < n ; j ++)
            g[i][j+1] = str[j] == '.';
    }
    int ii = 1, jj = j;
    int from = 1; // from above
    int L = 0, R = 0;
    while (ii != n && jj != n) {
        for (int w = from + 1 ; w != from ; w = (w + 1)%4) {
            int tox = ii + dx[w], toy = jj + dy[w];
            if (g[tox][toy]) {
                ii = tox;
                jj = toy;
                break;
            }
        }
    }
    return 0;
}