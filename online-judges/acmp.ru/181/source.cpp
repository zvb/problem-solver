#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

const int N = 110;

string D[N];
int cnt[N][N];
char d[] = {'N', 'S', 'W', 'E', 'U', 'D'};

int memo[N][N], found[N][N];

int rec(char c, int n) {// next move to D[c]
    //cout << "state " << c << ' ' << n << endl;
    if (n == 1) return 1;
    if (found[c][n]) return memo[c][n];
    found[c][n] = 1;
    int res = 1; // D[c]
    for (int i = 0 ; i < 6 ; i ++) {
        int num = cnt[c][d[i]];
        res += num * rec(d[i], n - 1);
    }
    return memo[c][n] = res;

}
int rec2(char c, int n) {
    if (n == 1) return 1;
    if (found[c][n]) return memo[c][n];
    found[c][n] = 1;
    int res = 0; // D[c]
    for (int i = 0 ; i < D[c].size() ; i ++) {
        res += rec2(D[c][i], n - 1);
    }
    return memo[c][n] = res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 0 ; i < 6 ; i ++) {
        getline(cin, D[d[i]]);
        for (int j = 0 ; j < D[d[i]].length() ; j ++)
            cnt[d[i]][D[d[i]][j]] ++;
    }
    char c; int n;
    cin >> c >> n;
    cout << rec(c, n) << endl;
    /*
    for (int i = 0 ; i < 6 ; i ++)
        cout << d[i] << ' ';
    cout << endl;
    for (int i = 0 ; i < 6 ; i ++) {
        cout << d[i] << ":\n";
        for (int j = 0 ; j < 6 ; j ++)
            cout << cnt[d[i]][d[j]] << ' ';
        cout << endl;
    }
     */
    return 0;
}