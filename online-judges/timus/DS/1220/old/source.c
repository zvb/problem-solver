#include <stdio.h>


int s[100003];

unsigned short p[100003], h[1003];
//unsigned int pi[3126], hi[32];
_Bool pi[100003], hi[1003];
int ptr = 1;
char str[5];

int main() {
  //printf("%lu\n", sizeof(_Bool));
  //printf("%lu\n", sizeof(p) + sizeof(h) + sizeof(pi) + sizeof(hi) + sizeof(s));
  int q;
  scanf("%d", &q);
  int x, num, val;
  while (q --) {
    scanf("%s ", str);
    if (str[1] == 'U') {
      scanf("%d %d", &x, &num);
      s[ptr] = num;
      p[ptr] = h[x];
      pi[ptr] = hi[ptr];


      h[x] = ptr & 0xffff;
      hi[x] = (ptr >> 16) & 1;
      //printf("h[x], hi[x] = %d, %d\n", h[x], hi[x]);

      ptr ++;
    } else {
      scanf("%d", &x);
      val = h[x] | (hi[x] << 16);
      //printf("val = %d\n", val);
      printf("%d\n", s[val]);
      h[x] = p[val];
      hi[x] = pi[val];

    }
  }
  return 0;
}
