#include <stdlib.h>
#include <stdio.h>


const int N = 55;
const long long s60 = 1ll << 60;

long long a[5005][2];
long long b[5005][2];
int numb[5005][2];
int sz[5005];

int n;

long long bb;
int bbn;
long long diff, o;
int zr, carry;


int ok(int i, int j) {
    bb = b[j][0];
    bb |= s60;
    bbn = numb[j][0] + 1;
    
    diff = bb - a[i][0];
    o = diff & bb;
    zr = bbn - __builtin_popcountll(o);
    carry = 0;
    if ((diff & (1ll << 60)) == 0) {
        zr--;
        carry = 1;
    }
    
    bb = b[j][1];
    bb |= s60;
    bbn = numb[j][1] + 1;
    
    diff = bb - (a[i][1] | carry);
    o = diff & bb;
    zr += bbn - __builtin_popcountll(o);
    
    if ((diff & s60) == 0)
        zr--;
    
    return zr & 1;
}
int i, j;

int main() {
    scanf("%d", &n);
    for ( i = 1 ; i <= n ; i ++) {
        scanf("%d", &sz[i]);
        for (j = 1 ; j <= sz[i] ; j ++) {
            int x;
            scanf("%d", &x);
            int posA = 2 * x - 2;
            int posB = 2 * x - 1;
            if (posA < 50)
                a[i][0] |= (1ll << posA);
            else
                a[i][1] |= (1ll << (posA - 50));
            if (posB < 50)
                b[i][0] |= (1ll << posB);
            else
                b[i][1] |= (1ll << (posB - 50));
        }
        numb[i][0] = __builtin_popcountll(b[i][0]);
        numb[i][1] = __builtin_popcountll(b[i][1]);
    }
    int ans = 0;
    
    for (i = 1 ; i <= n ; i ++) {
        for (j = i + 1 ; j <= n ; j ++) {
            if (ok(i, j))
                ans ++;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}