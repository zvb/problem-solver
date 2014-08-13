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
int ptr[255];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d ", &n, &k);
    gets(s + 1);
    
    
   
    for (int i = 1 ; i <= n ; i ++) {
        ps[s[i]].push_back(i);
    }

    
    long long ans = 0;
    for (int i = 1 ; i <= n ; i ++) {
        int pos = n;
        
        for (char c = '0' ; c <= '9' ; c ++) {
            if (ptr[c] + k < ps[c].size())
                pos = min(pos, ps[c][ptr[c] + k] - 1);
        }
        for (char c = 'a' ; c <= 'z' ; c ++) {
            if (ptr[c] + k < ps[c].size())
                pos = min(pos, ps[c][ptr[c] + k] - 1);
        }
        ptr[s[i]] ++;
        
        //cout << "i = " << i << "added " << pos - i + 1 << endl;
        
        ans += pos - i + 1;
    }
    cout << ans << endl;
    
    return 0;
}