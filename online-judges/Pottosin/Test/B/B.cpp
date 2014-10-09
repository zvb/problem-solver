#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 50005;

char s[N];
int m, n;
int set[255]; int size = 0;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    gets(s);
    scanf("%d", &m);
    n = strlen(s);
    for (int i = 0 ; i < n ; i ++)
        s[i] = tolower(s[i]);
    int ans = 0;
    for (int i = 0, j = 0; i < n; i ++) {
        //cout << "i = " << i << endl;
        while (j < n && size <= m) {
            if ( set[s[j]] == 0 && size == m ) {
                break;
            }
            set[s[j]] ++;
            if (set[s[j]] == 1)
                size ++;
            j ++;
        }
        //cout << "j = " << j << endl;
        ans += (j - i);
        set[s[i]] --;
        if (set[s[i]] == 0)
            size --;
    }
    printf("%d\n", ans);
    
    
    return 0;
}