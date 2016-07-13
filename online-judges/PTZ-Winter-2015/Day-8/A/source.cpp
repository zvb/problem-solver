#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cassert>


using namespace std;

#define filename "ambitious"

enum Type {DRONE, FORT, TOWER};

struct point {
    int x, y;
    Type type;
    point() {}
    point(int _x, int _y): x(_x), y(_y) {}
    point operator-(const point& o) const { return point(x - o.x, y - o.y); }
    point operator+(const point& o) const { return point(x + o.x, y + o.y); }
    long long operator*(const point& o) const { return x*o.y - y*o.x; }
    point operator*(double scalar) { return point(x*scalar, y*scalar); }
    long long operator^(const point& o) const { return x*o.x + y*o.y; }
    double r() { return sqrt(x*x+y*y); }
    double arg() { return (fabs(y) < 1e-9 && fabs(x) < 1e-9) ? 0.0 : atan2(y, x);}
    point operator%(double ang) { // rotate by ang radians CCW
        double R = r(), theta = arg() + ang;
        return point(R*cos(theta), R*sin(theta));
    }
    point normalized(double norm = 1.0) {              // get normalized
        double R = r();
        return point(x*norm/R, y*norm/R);
    }
    void scan() { scanf("%d%d", &x, &y); }
};


const int N = 1550;

int n, m, t;
point drones[N], forts[N], towers[N];

vector<point> v;

point o;

bool cmp(const point& l, const point& r) {
    return (l-o).arg() < (r - o).arg();
}


int main() {
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0 ; i < n ; i++) {
            drones[i].scan();
            drones[i].type = DRONE;
        }
        scanf("%d", &m);
        for (int i = 0 ; i < m ; i++) {
            forts[i].scan();
            forts[i].type = FORT;
        }
        scanf("%d", &t);
        for (int i = 0 ; i < t ; i++) {
            towers[i].scan();
            towers[i].type = TOWER;
        }
        
        long long ans = 0;
        for (int f = 0 ; f < m ; f ++) {
            o = forts[f];
            v.clear();
            for (int i = 0 ; i < n ; i ++) {
                v.push_back(drones[i]);
            }
            for (int i = 0 ; i < t ; i ++)
                v.push_back(towers[i]);
            
            sort(v.begin(), v.end(), cmp);
            
            int vs = v.size();
            
            int p1 = -1, p2 = -1, p3 = -1;
            for (int i = 0 ; i < vs ; i++) {
                if (v[i].type == TOWER) {
                    p1 = i;
                    break;
                }
            }
            assert(p1 != -1);
            p2 = p1;
            
            int r = 0;
            while ( (v[(p2 + vs - 1)%vs] - o) * (v[p1] - o) > 0) {
                p2 = (p2 - 1 + vs)%vs;
                r ++;
            }
            
            p3 = p1;
            int l = 0;
            while ( (v[p2] - o) * (v[(p3 + 1)%vs] - o)  > 0) {
                p3 = (p2 + 1)%vs;
                l ++;
            }

            while ( p1 < vs ) {
                ans += 1ll * r * l;
                
            }
            
            
        }
    }
    
    
    return 0;
}