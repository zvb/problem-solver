#include <iostream>
#include <cstdio>

using namespace std;

int s[100005], pr[100005];
int ptr = 1;
char str[5];
int mag = ~( (1 << 20) - 1 );
int main() {
  int q;
  scanf("%d", &q);
  int x, num, val;
  while (q --) {
    scanf("%s ", str);
    if (str[1] == 'U') {
      scanf("%d %d", &x, &num);
      s[ptr] = num;
      pr[ptr] &= mag;
      pr[ptr] |= pr[x] >> 20;
      pr[x] &= ~mag;
      pr[x] |= ptr << 20;
      ptr ++;
    } else {
      scanf("%d", &x);
      printf("%d\n", s[pr[x] >> 20]);
      val = pr[pr[x] >> 20] & (~mag); // head[x]
      pr[x] &= ~mag;
      pr[x] |= val;
    }
  }
  return 0;
}
