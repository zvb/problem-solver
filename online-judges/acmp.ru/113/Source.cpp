#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1005;

int u[N][N];
char g[N][N];
int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d ", &n);
    for (int i = 1 ; i <= n ; i ++)
        gets(g[i] + 1);
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= n ; j ++) {
            if (g[i][j] == '0')
                u[i][j] = 0;
            else
                u[i][j] = u[i-1][j] + 1;
        }
    }
    vector<pair<int,int> > l;
    int best = 0;
    for (int i = 1; i <= n ; i ++) {
        for (int j = 1 ; j <= n + 1 ; j ++) {
            //cout << u[i][j] << ' ';
            while (!l.empty() && l.back().second > u[i][j]) {
                best = max(best, (j - 1 - l.back().first + 1) * l.back().second);
                l.pop_back();
            }
            if (j != n + 1)
                l.push_back(make_pair(j, u[i][j]));
        }
        //cout << endl;
    }
    cout << best << endl;

    return 0;
}