#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

const int N = 50;
string s;
int n;

int memo[N][N];
int found[N][N];

int rec(int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;


    if (found[i][j]) return memo[i][j];
    found[i][j] = 1;
    
    

    
    return memo[i][j] = rec(i + 1, j) + rec(i, j - 1) - rec(i + 1, j - 1) +
        (s[i] == s[j] ? rec(i + 1, j - 1) + 1 : 0);
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    getline(cin, s);
    n = s.length();
    cout << rec(0, n - 1) << endl;
    return 0;
}