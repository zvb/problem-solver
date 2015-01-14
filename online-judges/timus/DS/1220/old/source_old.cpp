#include <cstdio>

using namespace std;

int head[1001], s[100005], pr[100005];
int ptr = 1;
char str[5];

int main() {
  //ios_base::sync_with_stdio(0);
  int q;
  //cin >> q;
  scanf("%d", &q);
  int x, num;
  while (q --) {
    //cin >> str;
    scanf("%s ", str);
    if (str[1] == 'U') {
      //cin >> x >> num;
      scanf("%d %d", &x, &num);
      s[ptr] = num;
      pr[ptr] = head[x];
      head[x] = ptr;
      ptr ++;
    } else {
      //cin >> x;
      scanf("%d", &x);
      //cout << s[head[x]] << '\n';
      printf("%d\n", s[head[x]]);
      head[x] = pr[head[x]];
    }
    //printf("s = %s\n", str);
  }
  return 0;
}
