#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 300;

int cmp[300][300];
int eq[300][300];

int n;
string s[N];

const char sp = 'a' - 1;

int color[N];

int ok = 1;

vector<char> top;

void dfs(int v) {
    color[v] = 1;
    for (int i = 'a' - 1 ; i <= 'z' ; i ++) {
        if (cmp[v][i] < 0) {
            if (color[i] == 1) {
                ok = 0;
                return;
            } else if (color[i] == 0) {
                dfs(i);
            }
        }
    }
    color[v] = 2;
    top.push_back(v);
}


int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        cin >> s[i];
    }
    for (int i = 0 ; i < 100 ; i ++) {
        for (int j = 0 ; j + 1 < n ; j ++) {
            string l = s[j].substr(0, min(i, (int)s[j].length()));
            string r = s[j + 1].substr(0, min(i, (int)s[j + 1].length()));
            if (l == r) {
                //cout << l << ' ' << r << endl;
                char lc = s[j].length() > i ? s[j][i] : sp;
                char rc = s[j + 1].length() > i ? s[j + 1][i] : sp;
                if (lc == rc) continue;
                //cout << lc << ' ' << rc << endl;
                if (cmp[lc][rc] > 0) {
                    puts("Impossible");
                    return 0;
                }
                cmp[lc][rc] = -1;
            }
        }
    }
    
    for (char i = 'a' ; i <= 'z' ; i ++) {
        if (cmp[i][sp] < 0) {
            puts("Impossible");
            return 0;
        }
    }
    
    for (int i = 'a' - 1 ; i <= 'z' && ok != 0 ; i ++) {
        if (color[i] == 0)
            dfs(i);
    }
    if (!ok) {
        puts("Impossible");
        return 0;
    }
    
    reverse(top.begin(), top.end());
    for (int i = 0 ; i < top.size(); i ++) {
        if (top[i] != sp)
            cout << top[i];
    }
    cout << endl;
    /*
    for (int i = 'a' - 1 ; i <= 'z' ; i ++)
        for (int j = 'a' - 1;  j <= 'z' ; j ++)
            if (cmp[i][j] == -1)
                printf("%c < %c\n", i, j);
    */
    
    return 0;
}