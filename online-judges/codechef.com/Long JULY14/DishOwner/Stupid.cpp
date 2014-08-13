#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 10010;

int T, n, s[N];
int uf[N];
int mx[N], bel[N];
priority_queue<int> Q[N];



int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1 ; i <= n ; i ++) {
            scanf("%d", &s[i]);
            bel[i] = i;
            Q[i].push(s[i]);
        }
        
        int q;
        scanf("%d", &q);
        while (q --) {
            int t;
            scanf("%d", &t);
            if (t == 0) {
                int a, b;
                scanf("%d%d", &a, &b);
                //cout << a << '-' << b << endl;
                //for (int i = 1 ; i <= n ; i ++)
                  //  cout << bel[i] << ' ';
                if (bel[a] == bel[b]) {
                    puts("Invalid query!");
                    continue;
                }
                
                //cout << endl;
                int ra = bel[a], rb = bel[b];
                if (Q[ra].top() < Q[rb].top()) {
                    for (int i = 1 ; i <= n ; i ++) {
                        if (bel[i] == ra)
                            bel[i] = rb;
                    }
                } else if (Q[ra].top() > Q[rb].top()) {
                    for (int i = 1 ; i <= n ; i ++) {
                        if (bel[i] == rb)
                            bel[i] = ra;
                    }
                }
                
                
            } else {
                int a;
                scanf("%d", &a);
                //cout << "A = " << a << endl;
                //a = root(a);
                printf("%d\n", bel[a]);
            }
        }
    }
    
    
    
    return 0;
}