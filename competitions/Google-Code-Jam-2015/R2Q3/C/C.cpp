#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>


using namespace std;


const int N = 111;

int T;


int main() {
    
    freopen("C-large.in.txt", "r", stdin);
    freopen("C-large.out.txt", "w", stdout);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d",&T);
    for (int t = 1 ; t <= T ; t ++) {
        set<long long> d;
        int c, n, V;
        scanf("%d%d%d", &c, &n, &V);
        for (int i = 0 ; i < n ; i ++) {
            int x;
            scanf("%d", &x);
            d.insert(x);
            //cout << x << ' ';
        }
        //cout << endl;
        
        int ans = 0;
        bool running = 1;
        while (running) {
            long long cur_sum = 0;
            long long add = -1;
            for (set<long long>::iterator it = d.begin() ; it != d.end() ; it++) {
                if (cur_sum + 1 <= V && cur_sum + 1 < *it) {
                    add = cur_sum + 1;
                    break;
                }
                cur_sum += 1ll * c * (*it);
            }
            if (add > -1) {
                //cout << "added " << add << endl;
                d.insert(add);
                ans ++;
            } else {
                running = 0;
            }
        }
        long long total_sum = 0;
        for (set<long long>::iterator it = d.begin() ; it != d.end() ; it++) {
            total_sum += 1ll * (*it) * c;
        }
        while (total_sum < V) {
            //cout << "added " << total_sum + 1 << endl;
            total_sum += 1ll * (total_sum + 1) * c;
            ans ++;
        }
        printf("Case #%d: %d\n", t, ans);
    }

    
    return 0;
}
