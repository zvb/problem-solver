#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>

#define MAXN 30005
using namespace std;
const double inf = 1e100, pi = M_PI;

struct point {
    long long x, y;
    point operator-(point& o) {
        point ret = {x - o.x, y - o.y};
        return ret;
    }
    long long operator*(const point& o) const { return x*o.y - y*o.x; }
    long long operator^(const point& o) const { return x*o.x + y*o.y; }
    bool operator<(const point& o) const { return x < o.x || (x == o.x && y < o.y); }
};


int n;
long long d;
point r, l;

point p;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> d >> r.x >> r.y >> l.x >> l.y;
    cin >> n;
    for (int i = 0 ; i < n ;i ++) {
        cin >> p.x >> p.y;
        if ( (p^p) > (d*d) ) {
            //cout << "TOO FAR\n";
            cout << "NO\n";
            continue;
        }
        //cout << "cross: " << (r*p) << ' ' << p*l << endl;
        if ( (r*p) == 0) {
            if ( (r^p) >= 0 ) {
                cout << "YES\n";
            } else
                cout << "NO\n";
            continue;
        }
        if ( (p*l) == 0) {
            if ( (p^l) >= 0 ) {
                cout << "YES\n";
            } else
                cout << "NO\n";
            continue;
        }

        if ( (r*p) < 0 || (p*l) < 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        
    }
    
    
    
    
    return 0;
}