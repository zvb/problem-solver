#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int N = 55;
const long long s60 = 1ll << 60;

long long a1[5050], a2[5050];
long long b1[5050], b2[5050];
int numb1[5050], numb2[5050];

int n;

long long bb;
int bbn;
long long diff, o;
int zr, carry;

inline bool ok(int i, int j) {
    bb = b1[j];
    bb |= s60;
    bbn = numb1[j] + 1;
    
    diff = bb - a1[i];
    o = diff & bb;
    zr = bbn - __builtin_popcountll(o);
    carry = 0;
    if (!(diff & s60)) {
        zr--;
        carry = 1;
    }
    
    bb = b2[j];
    bb |= s60;
    bbn = numb2[j] + 1;
    
    diff = bb - (a2[i] | carry);
    o = diff & bb;
    zr += bbn - __builtin_popcountll(o);
    
    if (!(diff & s60))
        zr--;
    
    return zr & 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i ++) {
        int sz;
        scanf("%d", &sz);
        for (int j = 1 ; j <= sz; ++j) {
            int x;
            scanf("%d", &x);
            int posA = (x << 1) - 2;
            int posB = posB + 1;
            if (posA < 50)
                a1[i] |= (1ll << posA);
            else
                a2[i] |= (1ll << (posA - 50));
            if (posB < 50)
                b1[i] |= (1ll << posB);
            else
                b2[i] |= (1ll << (posB - 50));
        }
        numb1[i] = __builtin_popcountll(b1[i]);
        numb2[i] = __builtin_popcountll(b2[i]);
    }
    int ans = 0;
    
    for (int i = 1 ; i <= n ; ++i) {
        for (int j = i + 1 ; j <= n ; ++j) {
            if (ok(i, j))
                ans ++;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}