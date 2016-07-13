#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cassert>


using namespace std;

int n, k;

const int N = 42 * 42;

int c[N][N];
int c_in[N];
int was[N][N];
int a[N][N];

bool cmp(const int&a, const int& b) {
    /*int cntA = 0, cntB = 0;
    for (int i = 1; i <= k; i ++)
        cntA += c[a][i], cntB += c[b][i];
    return cntA >= cntB;*/
    return c_in[a] >= c_in[b];
}

vector<int> l;

void go(int v) {
    //cout << "going into " << v << endl;
    //getchar();
    l.push_back(v);
    for (int i = 1 ; i <= k ; i ++) {
        if (c[v][i] > 0 && c_in[i] > 1) {
            c[v][i] = 0;
            c_in[v] --;
            go(i);
            return;
        }
    }
    for (int i = 1 ; i <= k ; i ++) {
        if (c[v][i] > 0) {
            c[v][i] = 0;
            c_in[v] --;
            go(i);
            return;
        }
    }
}

int w[42][42][42][42];

int ans[4][4] = {{1,2,1,1}, {1,2,2,2}, {2,2,2,1}, {1,1,2,1} };

int main() {
    //ios_base::sync_with_stdio(0);
    //cin >> k;
    scanf("%d", &k);
    if (k == 2) {
        for (int i = 0 ; i < 4; i ++) {
            for (int j = 0 ; j < 4 ; j ++)
                printf("%d ", ans[i][j]);
            puts("");
        }
        return 0;
    }
    
    n = k * k;
    for (int i = 1 ; i <= k ; i ++) {
        for (int j = 1; j <= k ; j ++)
            c[i][j] = 1;
        c_in[i] = k;
    }
    go(1);
    /*cout << l.size() << endl;
    if (l.size() != k * k )
        cout << "Error1\n";
    for (int i = 0 ; i < l.size() ; i ++) {
        int i1 = i + 1;
        if (i1 == l.size())
            i1 = 0;
        if (was[l[i]][l[i1]])
            cout << "error\n" << l[i] << " and " << l[i1] << endl;
        was[l[i]][l[i1]] = 1;
    }
     */
    
    l.pop_back();
    int p = 0;
    
    //cout << endl;
    int shift = 0;
    for (int i = 0 ; i < k * k ; i ++) {
        shift += i + 1;
        if (shift > k * k)
            shift -= k*k;
        for (int j = 0 ; j < l.size() ; j ++) {
            //cout << l[(l.size() - shift + j)%l.size()] << ' ';
            printf("%d ", l[(l.size() - shift + j)%l.size()]);
            a[p][j] = l[(l.size() - shift + j)%l.size()];
        }
        puts("");
       
        p ++;
    }
    /*
    for (int i = 0 ; i + 1 < n ; i ++) {
        for (int j = 0 ; j + 1 < n ; j ++) {
            int &r = w[a[i][j]][a[i][j+1]][a[i+1][j]][a[i+1][j+1]];
            if (r) {
                assert(0);
                cout << a[i][j] << ' ' << a[i][j+1] << endl;
                cout << a[i+1][j] << ' ' << a[i+1][j+1] << endl;
            }
            r = 1;
        }
    }
     */
    return 0;
}