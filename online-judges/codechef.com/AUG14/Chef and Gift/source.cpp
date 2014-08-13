#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        int n, k;
        scanf("%d%d", &n, &k);
        int cnt = 0;
        for (int i = 0 ; i < n ; i ++) {
            int a;
            scanf("%d", &a);
            if (a%2 == 0)
                cnt ++;
        }
        if (k == 0) {
            if (cnt == n)
                puts("NO");
            else
                puts("YES");
            continue;
        }
        
        if (cnt >= k)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}