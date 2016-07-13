#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;


void pi(string& s, vector<int>& v) {
    v.clear();
    v.resize(s.length());
    v[0] = 0;
    for (int i = 1 ; i < s.length() ; i++) {
        int j = v[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = v[j-1];
        }
        if (s[i] == s[j])
            j ++;
        v[i] = j;
    }
}

string s;
string t[15];
int k;
int c[256];
string ts[15];

vector<int> p[15];

vector< pair<int, int> > seg;
vector< vector<int> > dp;

int main () {
    
    cin >> s;
    cin >> k;
    for (int i = 0 ; i < k ; i ++)
        cin >> t[i];
    for (int i = 0 ; i < 26 ; i ++) {
        cin >> c[i + 'a'];
    }
    
    for (int i = 0 ; i < k ; i ++) {
        ts[i] = t[i] + '#' + s;
    }
    for (int i = 0 ; i < k ; i ++)
        pi(ts[i], p[i]);
    
    for (int i = 0 ; i < k ; i ++) {
        for (int j = t[i].length() + 1 ; j < ts[i].length() ; j ++) {
            if (p[i][j] == t[i].length()) {
                seg.push_back(make_pair(j - 2*t[i].length(), j - t[i].length() - 1));
            }
        }
    }
    /*
    for (int i = 0 ; i < seg.size() ; i++) {
        cout << seg[i].first << ' ' << seg[i].second << endl;
        cout << s.substr(seg[i].first, seg[i].second - seg[i].first + 1) << endl;
    }
     */
    
    sort(seg.begin(), sort.end());
    dp.resize(seg.size() + 1);
    for (int i = 0 ; i < dp.size() ; i++)
        dp[i].resize(s.length() + 1);
    
    
    
    return 0;
}