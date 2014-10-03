#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int N = (int)1e5 + 100;

int n;

string f[N], l[N];
vector <string> all;
map<string, int> inv;
vector<int> can[N];
int pos[2*N];
int p[N], r[N], u[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1 ; i <= n ;i  ++) {
        cin >> f[i] >> l[i];
        inv[f[i]] = i;
        inv[l[i]] = i;
        all.push_back(f[i]);
        all.push_back(l[i]);
    }
    sort(all.begin(), all.end());
    for (int i = 1 ; i <= n ; i ++) {
        cin >> p[i];
        r[p[i]] = i;
    }
    for (int i = 0 ; i < all.size() ; i ++) {
        pos[i+1] = r[inv[all[i]]];
        //cout << pos[i+1] << ' ';
    }
    //cout << endl;
    int cur_pos = 1;
    for (int i = 0 ; i < all.size() ; i ++) {
        int ind = inv[all[i]];
        if (u[ind]) continue;
        if (pos[i+1] == cur_pos) {
            u[ind] = 1;
            cur_pos ++;
        }
    }
    //cout << cur_pos << endl;
    if (cur_pos != n + 1)
        cout << "NO\n";
    else
        cout << "YES\n";
    
    return 0;
}