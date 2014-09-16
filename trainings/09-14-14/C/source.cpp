#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;
const int N = 2100;

const double eps = 1e-12, inf = 1e50, pi = M_PI;

int n;

struct point {
    double x, y;
    point() {}
    point(double _x, double _y): x(_x), y(_y) {}
    point operator-(const point& o) const {
        return point(x - o.x, y - o.y);
    }
    double arg() {
        if (x == 0.0 && y == 0.0)
            return -inf;
        return atan2(y, x);
    }
    double operator^(const point& o) const {
        return x*o.x + y*o.y;
    }
    double operator*(const point& o) const {
        return x*o.y - y*o.x;
    }
    double norm() {
        return sqrt(x*x + y*y);
    }
};
point p[N];

int used[N][N];
int nxt[N][N];
vector< pair<double, int> > S[N];
double getA(int i, int j) {
    int ne = nxt[i][j];
    point ij = p[j] - p[i], ine = p[ne] - p[i];
    if ( (ij * ine) > 0 ) return acos( (ij^ine) / (ij.norm()*ine.norm()));
    return 2*pi - acos( (ij^ine) / (ij.norm()*ine.norm()));
}
int getNext(int i, int j) {
    double a = (p[j] - p[i]).arg();
    vector< pair<double, int> >::iterator it = lower_bound(S[j].begin(), S[j].end(), a);
    if (it == S[j].end()) it = S[j].begin();
    double d1 =
}

int main() {
    int tc = 1;
    while (true ) {
        scanf("%d", &n);
        if ( n == 0 )
            break;
        for (int i = 0 ; i < n ; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        for (int i = 0 ; i < n ; i ++)
            for (int j = 0 ; j < n ; j ++) {
                used[i][j] = nxt[i][j] = 0;
            }
        for (int i = 0 ; i < n ; i ++) {
            vector< pair<double, int> > s;
            for (int j = 0 ; j < n ; j ++)
                if (j != i)
                    s.push_back(make_pair((p[j]-p[i]).arg(), j));
            sort(s.begin(), s.end());
            for (int j = 0 ; j < n - 1 ; j ++) {
                nxt[i][s[j].second] = s[(j+1)%(n-1)].second;
            }
            S[i] = s;
        }
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++)
                if (j != i)
                    cout << nxt[i][j] << ' ';
                else
                    cout << -1 << ' ';
            cout << endl;
        }
        
        vector<int> ans;
        
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                if (i == j || used[i][j]) continue;
                int ii = i, jj = j;
                int len = 0;
                do {
                    cout << ii << ',' << jj << endl;
                    used[ii][jj] = 1;
                    int j1 = nxt[ii][jj];
                    int i1 = nxt[jj][ii];
                    if (getA(i, j) < getA(j, i))
                        ii = jj, jj = j1;
                    else
                        ii = jj, jj = i1;
                    len ++;
                } while (ii != i && jj != j);
                
                cout << "-----\n";
                
                ans.push_back(len);
            }
        }
        sort(ans.begin(), ans.end());
        printf("Case %d: ", tc++);
        for (int i = 0 ; i < ans.size() ; i ++) {
            if (i == 0 || ans[i] != ans[i-1])
                printf("%d ", ans[i]);
        }
        puts("");
    }
    
    return 0;
    
}