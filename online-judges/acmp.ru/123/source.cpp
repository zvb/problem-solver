#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[100];
int n, memo[100][100], found[100][100];

int rec(int i, int j) {
    if (i == n) {
        if (j == 0) return 1;
        return 0;
    }
    if (j < 0) return 0;
    if (found[i][j])
        return memo[i][j];
    found[i][j] = 1;
    if (s[i] == '(') return memo[i][j] = rec(i + 1, j + 1);
    if (s[i] == ')') return memo[i][j] = rec(i + 1, j - 1);
    return memo[i][j] = rec(i + 1, j + 1) + rec(i + 1, j - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    gets(s);
    n = strlen(s);
    cout << rec(0, 0) << endl;
    /*
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0; j < n ; j ++) {
            if (found[i][j])
                cout << memo[i][j] << ' ';
        }
        cout << endl;
    }
     */
    
    
    return 0;
}