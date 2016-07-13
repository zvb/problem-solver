/*
 *Day 1: Xiaoxu Guo Contest 3, Friday, January 30, 2015
 *Problem C. Random Points
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>



using namespace std;

#define filename ""

const int N = 2005, mod = (int)1e9 + 7;
const double pi = M_PI;

struct point {
    long long x, y;
    int ind;
    point() {}
    point(long long _x, long long _y): x(_x), y(_y) {ind = -1;}
    point(long long _x, long long _y, int _ind): x(_x), y(_y), ind(_ind) {}
    point operator-(const point& o) const {
        return point(x - o.x, y - o.y);
    }
    long long operator*(const point& o) const {
        return x*o.y - y*o.x;
    }
    void read() {
        cin >> x >> y;
    }
    void print() {
        cout << x << ',' << y << endl;
    }
    double arg() {
        if (x == 0 && y == 0)
            return -pi;
        return atan2(y, x);
    }
};


int n;


point p[N];
point v[N];
int u[N][N];
int vn;



point x;

bool cmp(const point& l, const point& r) {
    return (l-x).arg() < (r-x).arg();
}


int pow2[N];


int main() {
    scanf("%d", &n);
    
    for (int i = 0 ; i <= n ; i ++) {
        if (i == 0) pow2[i] = 1;
        else pow2[i] = (pow2[i-1]*2) % mod;
    }
    for (int i = 0 ; i < n ; i ++) {
        p[i].read();
        p[i].ind = i;
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i ++) {
        x = p[i];
        vn = 0;
        for (int j = 0 ; j < n ; j ++) {
            if (j != i)
                v[vn ++] = p[j];
        }
        x.print();
        cout << "\nfor \n";
        sort(v, v + vn, cmp);
        for (int i = 0 ; i < vn ; i++)
            v[i].print();
        int p1 = 0, p2 = 1;
        while (p1 < vn) {
            //ans -= 2;
            
            
            
            while (p2 != p1 && (v[p1] - x)*(v[p2]-x) >= 0)
                p2 = (p2 + 1) % vn;
            
            if (!u[x.ind][v[p1].ind]) {
                u[x.ind][v[p1].ind] = u[v[p1].ind][x.ind] = 1;
                cout << "considering pair " << x.ind << " and " << v[p1].ind << endl;
                cout << "p1, p2=" << p1 << ", " << p2 << endl;
                
                int forbidden = 0;
                if (p2 > p1)
                    forbidden = p2 - p1 - 1;
                else
                    forbidden = vn + p2 - p1 - 1;
                
                cout << "forbidden = " << forbidden << endl;
                //if (n > forbidden + 2) {
                ans = (ans + pow2[n-forbidden-1]);
                cout << "added\t\t\t" << pow2[n-forbidden - 1] << endl;
                //ans = (ans + pow2[n-forbidden-1]);
                
                //}
                
                
                //cout << "added\t\t\t" << pow2[n-forbidden-1] << endl;
            }
            
            p1 ++;
        }
    }
    cout << ans << endl;
    
    
    
    return 0;
}