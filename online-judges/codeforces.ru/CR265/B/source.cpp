#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int p[8][3];
int z[8][3];
struct p3 {
    int x, y, z;
    p3() {}
    p3(int a[3]) {
        x = a[0];
        y = a[1];
        z = a[2];
    }
    long long dist2(p3 o) {
        return 1ll*(o.x - x)*(o.x - x)+1ll*(o.y - y)*(o.y - y)+1ll*(o.z - z)*(o.z - z);
    }
};
p3 P[8];
int aux[3];
long long sq[3];

int ans[8][3];

bool check() {
    for (int i = 0 ; i < 8 ; i ++) {
        for (int j = 0 ; j < 3 ; j ++)
            aux[j] = z[i][p[i][j]];
        P[i] = p3(aux);
    }
    
    for (int i = 0 ; i < 8 ; i ++) {
        map<long long, int> mp;
        for (int j = 0 ; j < 8 ; j ++) {
            if (i != j) {
                long long dist = P[i].dist2(P[j]);
                mp[dist] ++;
            }
        }
        /*
        cout << "HERE 1 " << endl;
        cout << mp.size() << endl;
        
        map<long long, int>::iterator it = mp.begin();
        for ( ; it != mp.end() ; it ++) {
            cout <<it->first << " " << it->second << endl;
        }
         */

        if (mp.size() != 3) return 0;
        map<long long, int>::iterator it = mp.begin();
        for (int j = 0 ; j < 3 && it != mp.end() ; j ++, it ++) {
            //cout << it->first << " " << it->second << endl;
            if (j < 2 && it->second != 3) return 0;
            if (j == 2 && it->second != 1) return 0;
            sq[j] = it->first;
        }
        //cout << "HERE 2 " << endl;
        sq[0] *= 6;
        sq[1] *= 3;
        sq[2] *= 2;
        for (int j = 0 ; j < 2 ; j ++) {
            if ( sq[j] != sq[j + 1]) return 0;
        }
        //cout << "HERE 3 " << endl;
    }
    for (int i = 0 ; i < 8 ; i ++) {
        for (int j = 0 ; j < 3 ; j ++) {
            ans[i][j] = p[i][j];
        }
    }
    return 1;
}

bool found = 0;

void rec(int i) {
    if (found) return;
    if (i == 7) {
        //cout << "checking " << endl;
        if (check()) {
            found = 1;
            //cout << "found!" << endl;
        } else {
            //cout << "not found " << endl;
        }
    } else {
        do {
            rec(i + 1);
        } while (next_permutation(p[i], p[i] + 3));
    }
    
}

int main() {
    for (int i = 0 ; i < 8 ; i ++) {
        for (int j = 0 ; j < 3 ; j ++) {
            scanf("%d", &z[i][j]);
            p[i][j] = j;
        }
    }
    /*
    if (check())
        cout << "YES";
    else
        cout << "NO";
     */

    rec(0);
    if (!found) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0 ; i < 8 ; i ++) {
            for (int j = 0 ; j < 3 ; j ++)
                printf("%d ", z[i][ans[i][j]]);
            puts("");
        }
    }

    
    
    return 0;
}