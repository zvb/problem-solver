#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int N = 105;

int g[N][N];

vector<int> G[N];
int color[N], ans[N];
int n;
bool ok = 1;
int num[N];
bool takeWithPlus[N];
pair<int, int> dp[N];

vector< pair<int, int> > pairs;

void dfs(int v, int c) {
    //cout << "dfs in " << v << endl;
    if (!ok) return;
    color[v] = c;
    num[c] ++;
    for (int i = 0 ; i < G[v].size() ; i ++) {
        int to = G[v][i];
        //cout << "trying to go in " << to << endl;
        if (color[to] == (c ^ 1))
            ; // OK
        else if (color[to] == c) {
            ok = 0; // NOT OK
            break;
        }
        else
            dfs(to, c ^ 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i ++) {
        int p;
        while (1) {
            scanf("%d", &p);
            if (!p) break;
            g[i][p] = 1;
        }
        color[i] = -1;
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = i + 1 ; j <= n ; j ++) {
            if (g[i][j] == 1 && g[j][i] == 1) {
                
            } else {
                G[i].push_back(j);
                G[j].push_back(i);
                //cout << "edge " << i << "---" << j << endl;
            }
        }
    }
    int cur = 0;
    for (int i = 1 ; i <= n && ok; i++) {
        if (color[i] == -1) {
            num[0] = num[1] = 0;
            dfs(i, cur);
            cur += 2;
            if (ok) {
                
            } else break;
        }
    }
    if (!ok) {
        puts("No solution");
        return 0;
    }
    for (int i = 1 ; i <= n ; i ++) {
        num[color[i]] ++;
    }
    for (int pa = 0 ; pa < cur; pa += 2) {
        dp[pa / 2] = make_pair(abs(num[pa] - num[pa + 1]), pa / 2);
    }
    int comps = cur / 2;
    sort(dp, dp + comps, std::greater<pair<int, int> >());
    int diff = 0;
    for (int i = 0 ; i < comps ; i ++) {
        if (diff < 0) {
            diff += dp[i].first;
            takeWithPlus[dp[i].second] = 1;
        } else {
            diff -= dp[i].first;
            takeWithPlus[dp[i].second] = 0;
        }
    }
    vector<int> f, s;
    for (int i = 0 ; i < comps ; i ++) {
        if (takeWithPlus[i]) {
            int gr = i*2;
            if (num[i*2+1] > num[i*2])
                gr ++;
            for (int j = 1 ; j <= n ; j ++) {
                if (color[j] == gr) {
                    f.push_back(j);
                } else if (color[j] == (gr^1)) {
                    s.push_back(j);
                }
            }
        } else {
            int gr = i*2;
            if (num[i*2+1] > num[i*2])
                gr ++;
            for (int j = 1 ; j <= n ; j ++) {
                if (color[j] == gr) {
                    s.push_back(j);
                } else if (color[j] == (gr^1)) {
                    f.push_back(j);
                }
            }
        }
    }
    assert(f.size() > 0);
    assert(s.size() > 0);
    printf("%d ", (int)f.size());
    for (int i = 0 ; i < (int)f.size() ; i ++)
        printf("%d ", f[i]);
    puts("");
    printf("%d ", (int)s.size());
    for (int i = 0 ; i < (int)s.size() ; i ++)
        printf("%d ", s[i]);
    puts("");
    return 0;
}







