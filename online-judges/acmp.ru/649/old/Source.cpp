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
vector<int> ps[36];
bool was[255];
int p[36][N];


// a: 1, 3, 4, 5, 9
//    1  2  3  4  5  6  7  8  9
// a: 1, 1, 2  3  4  4  4  4  5
// i = 2, k = 3
//       ^
//             ^

// a: 1, 3, 4, 5, 9
//    1  2  3  4  5  6  7  8  9
// a: 1, 1, 2  3  4  4  4  4  5
// i = 3, k = 3
//       ^
//             ^
//    0  1  2  3  4  5  6  7  8  9
// 7:    1  1  1  1  1  1  1  1  1
// 7: 1
int sz[36];


int mp[255];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cout << sizeof(p) << endl;
    scanf("%d%d ", &n, &k);
    gets(s + 1);
    for (char c = '0' ;c <= '9' ; c ++)
        mp[c] = c - '0';
    for (char c = 'a' ; c <= 'z' ; c ++)
        mp[c] = c - 'a' + 10;
    
    for (int i = 1 ; i <= n ; i++)
        sz[mp[s[i]]] ++;
    
    for (int i = 0 ; i < 36 ; i ++)
        ps[i].reserve(sz[i] + 1);
    
    for (int i = 1 ; i <= n ; i ++) {
        ps[mp[s[i]]].push_back(i);
        was[s[i]] = 1;
        for (char c = '0' ; c <= '9' ; c ++) {
            p[mp[c]][i] = p[mp[c]][i-1];
        }
        for (char c = 'a' ; c <= 'z' ; c ++) {
            p[mp[c]][i] = p[mp[c]][i-1];
        }
        p[mp[s[i]]][i] ++;
        
    }

    long long ans = 0;
    for (int i = 1 ; i <= n ; i ++) {
        int pos = n;
        for (char c = '0' ; c <= '9' ; c ++) {
            if (!was[c])
                continue;
            int ind = p[mp[c]][i];

            if (ind > 0 && ps[mp[c]][ind - 1] >= i)
                ind --;
            //cout << c << endl;
            
            //cout << "ind = " << ind << endl;
            
            //cout << "ps[c][ind] = " << ps[c][ind] << endl;
            
            int nxt = ind + k;
            
            //cout << "nxt = " << nxt << endl;
            if (nxt >= ps[mp[c]].size())
                continue;
            int p2 = ps[mp[c]][nxt] - 1;
            //cout << "p2 = " << p2 << endl;
            if (pos > p2)
                pos = p2;
        }
        for (char c = 'a' ; c <= 'z' ; c ++) {
            if (!was[c])
                continue;
            
            //cout << c << endl;
            int ind = p[mp[c]][i];
            

            
            if (ind > 0 && ps[mp[c]][ind - 1] >= i)
                ind --;
            //cout << "ind = " << ind << endl;
            
            int nxt = ind + k;
            //cout << "nxt = " << nxt << endl;
            if (nxt >= ps[mp[c]].size())
                continue;
            int p2 = ps[mp[c]][nxt] - 1;
            //cout << "p2 = " << p2 << endl;
            if (pos > p2)
                pos = p2;
        }
        //cout << "i = " << i << " pos = " << pos << endl;
        //cout << "added " << pos - i + 1 << endl << endl;
        ans += pos - i + 1;
    }
    cout << ans << endl;
    
    return 0;
}