#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>


using namespace std;

#define filename ""

const int N = 5555;

int n = 10;
int m = 0;

bool used[N];




int c[N][N];

void dfs(int v) {
    used[v] = 1;

    for (int i = 1 ; i <= n ; i ++) {
        if (!used[i] && c[v][i] > 0 && i != v) {
            dfs(i);
        }
    }
}

bool isConnected() {
    for (int i = 1;  i <= n ; i ++)
        used[i] = 0;
    dfs(1);
    if (used[n]) return 1;
    return 0;
}


set<pair<int, int> > st;

int main() {
    srand(time(0) + clock());
    for (int i = 0 ; i < 2*n  ; i ++) {
        int a = rand()%n + 1, b = rand()%n + 1;
        if (a > b) swap(a, b);
        if (a != b && c[a][b] == 0 && st.count(make_pair(a, b)) == 0) {
            c[a][b] = c[b][a] = 1;
            m ++;
            st.insert(make_pair(a, b));
        }
    }
    while(!isConnected()) {
        int a = rand() % n + 1, b = rand() %n + 1;
        if (a > b) swap(a, b);
        while (a == b || st.count(make_pair(a, b)) > 0) {
            
            a = rand() % n + 1; b = rand() %n + 1;
            if (a > b) swap(a, b);
        }
        c[a][b] = c[b][a] = 1;
        st.insert(make_pair(a, b));
        m ++;
    }
    
    
    printf("%d %d\n", n, m);
    for (set<pair<int, int> >::iterator it = st.begin() ; it != st.end(); it ++) {
        printf("%d %d\n", it->first, it->second);
    }
    return 0;
}