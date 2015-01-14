#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char str[20], s[20];

int main() {
    int t, n;
    scanf("%d\n", &t);
    for (int tt = 1 ; tt <= t ; tt ++) {
        gets(s);
        // geting smalest
        memcpy(str, s, 20 * sizeof(s[0]));
        n = strlen(str);
        int N ;
        sscanf(str, "%d", &N);
        
        int mn = 1 << 30, mx = -1;
        
        for (int i = 0 ; i < n ; i ++) {
            for (int j = i + 1 ; j < n ; j ++) {
                swap(str[i], str[j]);
                if (str[0] != '0') {
                    int num = 0;
                    
                    sscanf(str, "%d", &num);
                    
                    if (mn > num)
                        mn = num;
                    if (mx < num)
                        mx = num;
                }
                swap(str[i], str[j]);
            }
        }
        
        
        printf("Case #%d: %d %d\n", tt, min(mn, N), max(mx, N));
    }
    
    return 0;
}
