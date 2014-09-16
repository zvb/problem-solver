#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = (int)1e5 + 10, mod = (int)1e9+7;

char s[N];

int main() {
    int t;
    scanf("%d ", &t);
    while (t --) {
        gets(s);
        int n = strlen(s);
        int cur = 1;
        for (int i = 0 ; i < n ; i ++) {
            if ((i & 1) == 0) {
                if (s[i] == 'l')
                    cur = 2*cur;
                else
                    cur = 2*cur + 2;
            } else {
                if (s[i] == 'l')
                    cur = 2*cur - 1;
                else
                    cur = 2*cur + 1;
            }
            cur = (cur%mod + mod)%mod;
        }
        printf("%d\n", cur);
    }
    
    return 0;
}