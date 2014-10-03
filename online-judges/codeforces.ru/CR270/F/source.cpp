#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int N = (int)1e4 + 100;

vector<pair<int, int> > res;

void gauss(int X[N], int n, ind[N]) {
    for (int col = 0, row = 0 ; col < 32 && row < n ; col ++) {
        int sel = row;
        for (int i = row ; i < n ; i ++) {
            if ( (X[i] & ( 1 << col)) > 0 ) {
                sel = i;
            }
        }
        swap(X[row], X[sel]);
        swap(ind[row], ind[sel]);
        for (int i = 0 ; i < n ; i ++) {
            if (row != i) {
                X[i] ^= X[row];
                res.push_back(make_pair(ind[i], ind[row]));
            }
        }
        row ++;
    }
}

int n;
int x[N], y[N];



int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &x[i]);
        ind[i] = i;
    }
    
    for (int i = 0 ; i < n ; i++)
        scanf("%d", &y[i]);
    
    gauss(x, n);
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < 5 ; j ++) {
            printf("%d ", (x[i] >> j) & 1);
            
        }
        puts("");
    }
    
    
    return 0;
}