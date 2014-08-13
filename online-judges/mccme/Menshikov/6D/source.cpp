#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#define N 111

using namespace std;
int n;
struct Rect {
    int x, y, w, h;
};

Rect r[N];

struct Event {
    int x, ind, opening;
    bool operator<(const Event& r) const {
        return x < r.x;
    }
};

Event events[2*N]; int en = 0;
multiset<pair<int, int> > sweep;
Event v[2*N]; int vn = 0;
pair<int, int> s[N]; int sn = 0;
int u[2*N];

long long H() {
    vn = sn = 0;
    for (std::set<pair<int, int> >::iterator it = sweep.begin();
         it != sweep.end() ; it ++) {
        s[sn ++] = *it;
    }
    if (sn <= 0) return 0;
    for (int i = 0 ; i < sn ; i ++) {
        Event e = {s[i].first, i, 1};
        v[vn ++] = e;
        e.x = s[i].second; e.opening = 0;
        v[vn ++] = e;
    }
    
    sort(v, v + vn);
    long long res = 0;
    int cnt = 0;
    int last = 0;
    for (int i = 0 ; i < vn ; i ++) {
        if (v[i].opening) {
            cnt ++;
            if (cnt == 1) last = v[i].x;
        }
        else {
            cnt --;
            if (cnt == 0) {
                res += v[i].x - last;
                last = 0;//
            }
        }
    }
    return res;
    
}

int main() {
    long long A = 0; // area
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i ++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        r[i].x = min(x1, x2);
        r[i].y = min(y1, y2);
        r[i].w = x1 + x2 - 2*r[i].x;
        r[i].h = y1 + y2 - 2*r[i].y;
        Event e = {r[i].x, i, 1};
        events[en ++] = e;
        e.x = r[i].x + r[i].w; e.opening = 0;
        events[en ++] = e;
    }
    sort(events, events + en);
    int last = 0;
    for (int j = 0 ; j < en ; j ++) {
        //cout << "j = " << j << endl;
        int ind = events[j].ind;
        A += H() * (events[j].x - last);
        last = events[j].x;
        //cout << "x = " << events[j].x << endl;
        //cout << "A = " << A << endl;

        if (events[j].opening)
            sweep.insert(make_pair(r[ind].y, r[ind].y + r[ind].h));
        else {
            //cout << "Erasing " << endl;
            //if (sweep.find(make_pair(r[ind].y, r[ind].y + r[ind].h)) == sweep.end())
            //    cout << "END\n";
            sweep.erase(sweep.find(make_pair(r[ind].y, r[ind].y + r[ind].h)));
        }
        
    }
    cout << A << endl;
    
    return 0;
}