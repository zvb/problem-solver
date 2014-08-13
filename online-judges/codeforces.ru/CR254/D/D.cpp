#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int N = (int)1e5 + 100;
int TL = 0;
string s;
int q;
string a[N], b[N], all[2*N];
int ans[N];
int qa[N], qb[N], u[N];
map<string, int> mp;
map< pair<int,int>, vector<int> > p2q;

vector<int> oc[2*N];
vector<int> heavy, light;

int T = 0;
int main() {
    getline(cin, s);
    cin >> q;
    for (int i = 0 ; i < q ; i ++) {
        ans[i] = 1 << 30;
        cin >> a[i] >> b[i];
        if (mp.count(a[i])) {
            qa[i] = mp[a[i]];
        } else {
            all[T] = a[i];
            mp[a[i]] = T;
            qa[i] = T ++;
        }
        
        if (mp.count(b[i])) {
            qb[i] = mp[b[i]];
        } else {
            all[T] = b[i];
            mp[b[i]] = T;
            qb[i] = T ++;
        }
        int ta = mp[a[i]], tb = mp[b[i]];
        if (ta > tb) swap(ta, tb);
        p2q[make_pair(ta, tb)].push_back(i);
    }
    TL = 2 * s.length() / (int)(sqrt(q) + 1) + 1;
    for (int i = 0 ; i < s.length(); i ++) {
        for (int len = 1 ; len <= 4 ; len ++) {
            if (i + len <= s.length()) {
                string t = s.substr(i, len);
                map<string, int>::iterator it = mp.find(t);
                if (it == mp.end()) continue;
                oc[it->second].push_back(i);
            }
        }
    }
    for (int i = 0 ; i < T ; i ++) {
        
        if (mp.count(all[i]) == 0) continue;
        
        if (oc[i].size() >= TL)
            heavy.push_back(i);
        else
            light.push_back(i);
    }
    for (int i = 0 ; i < heavy.size(); i ++) {
        int ind = heavy[i];
        // oc[ind] -> where it occurs in string s.
//        cout << "processing " << all[ind] << " with ind = " << ind << endl;
        
        int p1 = 0, p2 = 0;
        for (int j = 0 ; j < s.length() ; j ++) {
            for (int len = 1 ; len <= 4 ; len ++) {
                if (j + len <= s.length()) {
                    string x = s.substr(j, len);
                    map<string, int>::iterator it = mp.find(x);
                    if (it == mp.end()) continue;
                    int ix = it->second;
                    int ia = ind, ib = ix;
                    if (ia > ib) swap(ia, ib);
                    map< pair<int,int>, vector<int> >::iterator it2 = p2q.find(make_pair(ia, ib));
                    if (it2 == p2q.end()) continue;
                    
//                    cout << "with " << x << endl;
                    
                    vector<int> &ref = it2->second;
                    
                    
                    while (p1 < oc[ind].size() && oc[ind][p1] < j) {

                        int h = oc[ind][p1];
                        //cout << "1:h = " << h << " j = " << j << endl;

                        for (int k = 0 ; k < ref.size() ; k ++) {
                            int d = max(j + len, h + (int)all[ind].length()) - min(h, j);
                            //cout << "trying to relax with " << d << endl;
                            ans[ref[k]] = min(ans[ref[k]], d);
                        }
//                      if (oc[ind][p1] < j)
                            p1 ++;
                    }
                    if (p1 < oc[ind].size()) {
                        int h = oc[ind][p1];
                        //cout << "2:h = " << h << " j = " << j << endl;
                    
                        for (int k = 0 ; k < ref.size() ; k ++) {
                            int d = max(j + len, h + (int)all[ind].length()) - min(h, j);
                            //cout << "trying to relax with " << d << endl;
                            ans[ref[k]] = min(ans[ref[k]], d);
                        }
                    }
                    if (p1 > 0)
                        p1 --;
                    /*
                    while (p1 + 1 < oc[ind].size() && oc[ind][p1 + 1] <= j)
                        p1 ++;
                    p2 = p1 + 1;
                    
                    cout << "p1 = " << p1 << ' ' << "p2 = " << p2 << endl;
                    vector<int> &ref = it2->second;
                    int h = oc[ind][p1];
                    cout << "h = " << h << endl;
                    if (h <= j) {
                        
                        for (int k = 0 ; k < ref.size() ; k ++) {
                            int d = max(j + len, h + (int)all[ind].length()) - h;
                            cout << "trying to relax with " << d << endl;
                            ans[ref[k]] = min(ans[ref[k]], d);
                        }
                    }
                    if (p2 < oc[ind].size() && oc[ind][p2] > j) {
                        for (int k = 0 ; k < ref.size() ; k ++) {
                            int d = max(j + len, oc[ind][p2] + (int)all[ind].length()) - j;
                            ans[ref[k]] = min(ans[ref[k]], d);
                        }
                    }
                     */
                                                                            
                }
            }
        }
        
    }
    for (int i = 0 ; i < q ; i ++) {
        if (ans[i] < (1 << 30))
            continue;
        vector<int>& v1 = oc[qa[i]];
        vector<int>& v2 = oc[qb[i]];
        int p1 = 0, p2 = 0;
        while (p1 < v1.size() && p2 < v2.size()) {
            int d = max(v1[p1] + all[qa[i]].length(), v2[p2] + all[qb[i]].length()) - min(v1[p1], v2[p2]);
            ans[i] = min(ans[i], d);
            if (v1[p1] < v2[p2]) p1 ++;
            else p2 ++;
        }
    }
    for (int i = 0 ; i < q ; i ++) {
        if (ans[i] < (1 << 30))
            printf("%d\n", ans[i]);
        else
            puts("-1");
    }
    
    
    
    return 0;
}