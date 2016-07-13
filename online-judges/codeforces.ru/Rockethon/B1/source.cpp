#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 100;








int findMth(int n, int m) {
    int p[10];
    
    vector< pair<int, int> > mp;
    for (int i = 1 ; i <= n ; i ++)
        p[i] = i;
    int k = 0;
    do {
        int val = 0;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = i ; j <= n ; j ++) {
                int ii = i, jj = j;
                if (ii > jj)
                    swap(ii, jj);
                int toAdd = 1 << 30;
                for (int t = ii ; t <= jj ; t++) {
                    toAdd = min(toAdd, p[t]);
                }
                val += toAdd;
                
            }
        }
        //cout << val << ' ' << k << endl;
        mp.push_back(make_pair(val, k));
        k ++;
    } while (next_permutation(p + 1, p + n + 1));
    
    sort(mp.begin(), mp.end());
    int mx = -1;
    int cnt = 0;
    for (int i = (int)mp.size() - 1 ; i >= 0 ; i--) {
        mx = max(mx, mp[i].first);
    }
    
    //cout << mx << endl;
    
    int numOfper = -1;
    for (int i = 0 ; i < mp.size() ; i++) {
        if (mp[i].first == mx) {
            
            cnt ++;
            if (cnt == m) {
                numOfper = mp[i].second;
                break;
            }
        }
    }
    k = 0;
    
    //cout << "numOfper = " << numOfper << endl;
    for (int i = 1 ; i <= n ; i ++)
        p[i] = i;
    do {
        if (k == numOfper) {
            for (int i = 1 ; i <= n ; i++)
                printf("%d ", p[i]);
            puts("");
            return 0;
        }
        
        
        k ++;
    } while (next_permutation(p + 1, p + n + 1));
    return 1;
}

int n, m;
int main() {
    scanf("%d%d", &n, &m);
    int mm = 1;
    while (1) {
        if (findMth(n, mm) == 1) {
            cout << "total = " << mm-1 << endl;
            break;
            
        }
        mm ++;
        
    }
    return 0;
}