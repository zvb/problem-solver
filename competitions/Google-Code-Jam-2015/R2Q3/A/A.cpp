#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>


using namespace std;


int T, r, c, w;


int main() {
    //freopen("A-large.in.txt", "r", stdin);
    //freopen("A-large.out.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for (int t = 1 ; t <= T ; t ++) {
    	scanf("%d%d%d", &r, &c, &w);
    	int ans;
    	if (r > 1) {
    		if (c % w == 0) {
    			ans = ((c + w - 1) / w - 1) * r + r + w - 1;
    		} else {
    			ans = ((c + w - 1) / w - 1) * r + 1 + w - 1;
    		}
    	} else {
    		ans = (c + w - 1) / w - 1 + w - 1 + 1;
    	}
    	printf("Case #%d: %d\n", t, ans);
    }

    
    return 0;
}
