#include <stdio.h>

unsigned short h[1001]; // need one more bit // 16

int ptr = 0; // current boundary
unsigned int st[100001]; // for numbers 400
unsigned short next[100001]; // next 200
char str[5];
int num, val;

int main() {
    int q;
    scanf("%d\n", &q);
    while (q --) {
        scanf("%s %d", str, &num);
        if (str[1] == 'U') { //push
            scanf("%d\n", &val);
            st[++ptr] = val;
            next[ptr] = h[num];
            if ( (st[num] >> 30) & 1 ) { // h^ bit % 17 == 1
                st[ptr] |= 1 << 31; // next[ptr]&31 = 1
            } else {
                if ( (st[ptr] >> 31) )
                    st[ptr] ^= 1 << 31;
            }
            h[num] = ptr & 0xffff;
            if ((ptr >> 16) & 1)
            st[num]
        } else {
            printf("%d\n", st[h[num]]);
            h[num] = next[h[num]];
        }
    }
    return 0;
}