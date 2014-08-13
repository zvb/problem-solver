#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = (int)1e6 + 10;

int n, k;
char s[N];
vector<int> ps[255];


// a: 1, 3, 4, 5, 9
// i = 2, k = 3
//       ^
//             ^

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d ", &n, &k);
    gets(s + 1);
    
    for (int i = 1 ; i <= n ; i ++) {
        ps[s[i]].push_back(i);
    }
    long long ans = 0;
    for (int i = 1 ; i <= n ; i ++) {
        int pos = n;
        for (char c = '0' ; c <= '9' ; c ++) {
            vector<int> &r = ps[c];
            int ind = lower_bound(r.begin(), r.end(), i) - r.begin();
            int nxt = ind + k;
            if (nxt >= r.size())
                continue;
            int p2 = r[nxt] - 1;
            if (pos > p2)
                pos = p2;
        }
        for (char c = 'a' ; c <= 'z' ; c ++) {
            vector<int> &r = ps[c];
            int ind = lower_bound(r.begin(), r.end(), i) - r.begin();
            int nxt = ind + k;
            if (nxt >= r.size())
                continue;
            int p2 = r[nxt] - 1;
            if (pos > p2)
                pos = p2;
        }
        //cout << "added " << pos - i + 1 << endl;
        ans += pos - i + 1;
    }
    cout << ans << endl;
    
    return 0;
}