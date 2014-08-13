#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = (int)1e5 + 100;

int n, s[N], u[N];
vector<int> p;
vector<pair<int, int> > ans;

void print(vector<int>& v) {
    for (int i = 0 ; i < v.size() ; i ++)
        printf("%d ", v[i]);
    puts("");
}

int main() {
    scanf("%d", &n);
    s[1] = 1;
    for (int i = 2 ; i <= n ; i ++) {
        if (!s[i]) {
            if (i <= n / 2)
                p.push_back(i);
            for (int j = 2*i ; j <= n ; j += i)
                s[j] = 1;
        }
    }
    for (int i = (int)p.size() - 1 ; i >= 0 ; i --) {
        vector<int> cur;
        for (int j = p[i] ; j <= n ; j += p[i])
            if (!u[j])
                cur.push_back(j);
        //print(cur);
        if (cur.size() & 1) {
            swap(cur[1], cur.back());
            cur.pop_back();
        }
        //print(cur);
        for (int j = 0 ; j < cur.size() ; j += 2) {
            ans.push_back(make_pair(cur[j], cur[j+1]));
            u[cur[j]] = u[cur[j+1]] = 1;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0 ; i < (int)ans.size() ; i ++)
        printf("%d %d\n", ans[i].first, ans[i].second);
    
    
    
    
    
    return 0;
}