#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n, T;
char s[(int)1e5 + 10];

int main() {
    scanf("%d ", &T);
    while (T --) {
        scanf("%d ", &n);
        gets(s);
        long long cnt = 0;
        for (int i = 0 ; i < n ; i ++)
            cnt += (int)(s[i] == '1');
        printf("%lld\n", cnt*(cnt + 1)/2);
    }
    return 0;
}