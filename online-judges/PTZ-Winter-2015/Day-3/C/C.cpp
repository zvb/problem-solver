#include <cstdio>

using namespace std;

const int N = 55;
const long long s60 = 1ll << 52;

long long a1[5050], a2[5050];
long long b1[5050], b2[5050];
int numb1[5050], numb2[5050];

const int sh = (1 << 18) - 1;

short int pr[1 << 18];

#define bp(x) (pr[(x) & sh] ^ pr[((x) >> 18) & sh] ^ pr[((x) >> 36) & sh])

int sz;

int n;

long long bb;
int bbn;
long long diff, o;
int zr, carry;

int main() {
    
    for (int i = 0 ; i < (1 << 18); i++) {
        pr[i] = pr[i >> 1] ^ (i & 1);
    }
    
    scanf("%d", &n);
    //std::ios_base::sync_with_stdio(0);
    //cin >> n;

    for (int i = 1 ; i <= n ; i ++) {
        scanf("%d", &sz);
        //cin >> sz;
        for (int j = 1 ; j <= sz ; j ++) {
            int x;
            scanf("%d", &x);
            //cin >> x;
            int posA = (x << 1) - 2;
            int posB = posA + 1;
            if (posA < 50)
                a1[i] |= (1ll << posA);
            else
                a2[i] |= (1ll << (posA - 50));
            if (posB < 50)
                b1[i] |= (1ll << posB);
            else
                b2[i] |= (1ll << (posB - 50));
        }
        numb1[i] = bp(b1[i]) & 1;
        numb2[i] = bp(b2[i]) & 1;
        //numb1[i] = pr[b1[i] & sh] ^ pr[(b1[i] >> 18) & sh] ^ pr[(b1[i] >> 36) & sh];
        //numb2[i] = pr[b2[i] & sh] ^ pr[(b2[i] >> 18) & sh] ^ pr[(b2[i] >> 36) & sh];
        b1[i] |= s60;
        b2[i] |= s60;
    }
    int ans = 0;
    long long t;
    
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = i + 1 ; j <= n ; j ++) {
            diff = b1[j] - a1[i];
            t = diff & b1[j];
            zr = (numb1[j] + 1 - bp(t)) & 1;
            carry = 0;
            if (!(diff & s60)) {
                zr ^= 1;
                carry = 1;
            }
            
            diff = b2[j] - (a2[i] | carry);
            t = diff & b2[j];
            zr ^= (numb2[j] + 1 - bp(t)) & 1;
            
            if (!(diff & s60))
                zr ^= 1;
            
            if (zr)
                ans++;
        }
    }
    
    printf("%d\n", ans);
    //cout << ans << '\n';
    return 0;
}