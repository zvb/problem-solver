#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

const int N = 1111;

struct point
{
	int x, y;
	long long operator*(const point& r) {
		return 1ll*x*r.y - 1ll*y*r.x;
	}
	point operator-(const point& r) const {
		point res = {x - r.x, y - r.y};
		return res;
	}
};

int n;
point o, p[N];
int u[N];

int main() {
    scanf("%d%d%d", &n, &o.x, &o.y);
    for (int i = 0 ; i < n ; i ++) {
    	scanf("%d%d", &p[i].x, &p[i].y);
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i ++) {
    	if (u[i])
    		continue;
    	ans ++;
    	for (int j = 0 ; j < n ; j ++) {
    		if (!u[j]) {
    			if ( (p[i] - o) * (p[j] - o) == 0)
    				u[j] = 1;
    		}
    	}
    }
    printf("%d\n", ans);
    
    
    return 0;
}
