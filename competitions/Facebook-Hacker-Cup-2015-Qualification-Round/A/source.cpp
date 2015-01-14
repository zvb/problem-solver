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
        for (int i = 0 ; i < n ; i ++) {
            int idx = -1;
            for (int j = n - 1 ; j > i ; j --) {
                if ( (idx == -1 || s[idx] > str[j]) && (i != 0 || str[j] != '0') ) {
                    idx = j;
                }
            }
            if (idx != -1 && str[i] > str[idx]) {
                swap(str[idx], str[i]);
                break;
            }
        }
        printf("Case #%d: %s ", tt, str);
        // getting largest
        memcpy(str, s, 20 * sizeof(s[0]));
        n = strlen(str);
        for (int i = 0 ; i < n; i ++) {
            int idx = -1;
            for (int j = n - 1 ; j > i ; j --) {
                if ( idx == -1 || s[idx] < str[j] ) {
                    idx = j;
                }
            }
            if (idx != -1 && str[i] < str[idx]) {
                swap(str[idx], str[i]);
                break;
            }
        }
        printf("%s\n", str);
    }
    
    return 0;
}
