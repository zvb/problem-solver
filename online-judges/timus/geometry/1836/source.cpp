#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

double eps = 1e-9;

struct point3 {
    double x, y, z;
    point3() {}
    point3(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
    point3 operator-(const point3& o) const { return point3(x-o.x, y-o.y, z-o.z); }
    point3 operator*(const point3& o) const {
        return point3(y*o.z - z*o.y, z*o.x - x*o.z, x*o.y - y*o.x);
    }
    double r() {
        return sqrt(x*x + y*y + z*z);
    }
    
};


double getCap(double x, double y, double z, double a) {
    //cout << "x, y, z " << x << ' ' << y << ' ' << z << endl;
    double arr[3] = {x, y, z};
    sort(arr, arr + 3);
    x = arr[0], y = arr[1], z = arr[2];
    double res = a * a * x / 2;
    y -= x, z -= x;
    res += a * a * (y + z) / 6;
    return res;
}
int a, d[4], q[4];
point3 p[4];


int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &a);
        assert(a != 0);
        int nonzero = -1;
        for (int i = 0 ; i < 4 ; i ++) {
            scanf("%d", &d[i]);
            if (d[i] > 0)
                nonzero = i;
        }
        if (nonzero < 0) {
            puts("0.0");
            continue;
        }
        int ambigious = 0;
        for (int i = 0 ; i < 4 ; i ++) {
            if (d[i] + d[ ( i + 1 ) % 4 ] == 0) {
                ambigious = 1;
                break;
            }
        }
        if (ambigious) {
            puts("ambigious");
            continue;
        }
        int ind = -1;
        for (int i = 0 ; i < 4 ; i ++)
            if (d[i] == 0)
                ind = i;
        
        if (d[0] + d[2] == d[1] + d[3]) {
            printf("%.12lf\n", 1.0 * a * a * (d[0] + d[2]) / 2);
        } else {
            int ind = -1;
            for (int i = 0 ; i < 4 ; i++)
                if (d[i] == 0)
                    ind = i;
            if (ind < 0) {
                puts("error");
                continue;
            }
            int p = 0;
            for (int i = ind; i < 4 ; i++)
                q[p ++] = d[i];
            for (int i = 0 ; i < ind ; i++)
                q[p ++] = d[i];
            double qn = q[1] + q[3] - q[2];
            if (qn < 0) {
                qn = -qn;
                //cout << "qn = " << qn << endl;
                //q[3] += qn; q[1] += qn;
                double res = 1.0 * a*a*(q[3] + qn + q[1] + qn) / 2 - 1.0 * qn * a * a;
                double x = qn * a / (q[3] + qn), y = qn * a / (q[1] + qn);
                //cout << x << ',' << y << endl;
                res += 1.0/6 * qn * x * y;
                printf("%.12lf\n", res);
            } else {
                puts("error");
            }
        }
        /*
        if (ind < 0) {
            p[0] = point3(0, 0, d[0]);
            p[1] = point3(a, 0, d[1]);
            p[2] = point3(a, a, d[2]);
            p[3] = point3(0, a, d[3]);
            point3 v01 = p[1] - p[0], v02 = p[2] - p[0], v03 = p[3] - p[0];
            point3 vi = v01 * v02, vii = v02 * v03;
            
            point3 v = vi * vii;
            if ( v.r() < 1.0 ) {
                double V = getCap(d[0], d[1], d[2], a) + getCap(d[0], d[3], d[2], a);
                //cout << "V = " << v.r() << endl;
                printf("%.12lf\n", V);
            } else {
                puts("error");
            }
        } else {
            
        }
         */
        
    }

    return 0;
}