#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

const int N = (int)1e5 + 100;

using namespace std;

struct SegTree {
    int n;
    int *a;
    SegTree() {}
    SegTree(int _n, int * arr) {
        n = _n;
        a = new int [4*n];
        for (int i = 0 ; i < 4*n ; i ++)
            a[i] = 0;
        build(1, 0, n-1, arr);
    } 
    void build(int v, int L, int R, int * arr) {
    	if (L == R) {
    		a[v] = arr[L];
    	} else {
    		int mid = ( L + R ) / 2;
    		build(2*v, L, mid, arr);
    		build(2*v + 1, mid + 1, R, arr);
    		a[v] = max(a[2*v], a[2*v+1]);
    	}
    }
    int get(int v, int L, int R, int l, int r) {
    	if (l > r) return 0;
        if (L == l && R == r) return a[v];
        int mid = ( L + R ) / 2;
        return max(get(2*v, L, mid, l, min(mid, r)), get(2*v+1, mid + 1, R, max(l, mid+1), r));
    }
    
};
SegTree t[5];
int a[5][N];
int ans[5];
int locMin[5];
int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0 ; i < n ; i++) {
    	for (int j = 0 ; j < m ; j ++) {
    		scanf("%d", &a[j][i]);
    	}
    }
    for (int j = 0 ; j < m ; j++) {
    	t[j] = SegTree(n, a[j]);
    }
    
    //cout << "here" << endl;
    int best = -1;
    for (int l = 0 ; l < n ; l ++) {
    	//cout << "l = " << l << endl;
    	int lo = l, hi = n - 1, mid;
    	long long total = 0;
    	while (hi > lo) {
    		//cout << "hi = " << hi << " lo = " << lo << endl;
    		mid = (lo + hi + 1) / 2;
    		//cout << "mid = " << mid << endl;
    		total = 0;
    		for (int j = 0 ; j < m ; j ++) {
    			total += t[j].get(1, 0, n-1, l, mid);
    		}
    		//cout << "total = " << total << endl;
    		if (total <= k) {
    			lo = mid;
    		} else {
    			hi = mid - 1;
    		}
    	}
    	total = 0;
		for (int j = 0 ; j < m ; j ++) {
			total += t[j].get(1, 0, n-1, l, lo);
		}
    	//cout << "final lo = " << lo << endl;
    	if (total <= k && lo - l + 1 > best) {
    		//cout << "here " << l << endl;
    		//cout << "total after " << total << endl;
    		for (int j = 0 ; j < m ; j++) {
    			ans[j] = t[j].get(1, 0, n-1, l, lo);
    		}
    		best = lo - l + 1;
    	}
    	//best = max(best, lo - l + 1);
    	//cout << "best = " << best << endl;
    }
    //printf("%d\n", best);
    for (int j = 0 ; j < m ; j ++) {
    	printf("%d ", ans[j]);
    }
    puts("");
    
    return 0;
}
