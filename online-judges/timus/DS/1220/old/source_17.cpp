#include <cstdio>

using namespace std;

int s[100002];

unsigned short p[100002], h[1001];
unsigned int pi[3126], hi[32];

int ptr = 1;
char str[5];

int main() {
  printf("%lu\n", sizeof(p) + sizeof(h) + sizeof(pi) + sizeof(hi) + sizeof(s));
  int q;
  scanf("%d", &q);
  int x, num, val;
  while (q --) {
    scanf("%s ", str);
    if (str[1] == 'U') {
      scanf("%d %d", &x, &num);
      s[ptr] = num;
      p[ptr] = h[x];
      if (hi[x / 32] & ( 1 << (x%32) )) 
	pi[ptr / 32] |= 1 << (ptr%32);
      else
	pi[ptr / 32] &= ~(1 << (ptr%32));
      h[x] = ptr & 0xffff;
      if (ptr & ( 1 << 17 ) )
	hi[x / 32] |= 1 << (x % 32);
      else
	hi[x / 32] &= ~(1 << (x%32));
      ptr ++;
    } else {
      scanf("%d", &x);
      val = h[x];
      if (hi[x / 32] & ( 1 << (x%32) ))
	val |= 1 << 17;

      printf("%d\n", s[val]);
      h[x] = p[val];
      if (pi[val/32] & (1 << (val%32)))
	hi[x / 32] |= 1 << (x%32);
      else
	hi[x / 32] &= ~(1 << (x%32));
    }
  }
  return 0;
}
