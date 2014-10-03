#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> d[2222];
int n;
int main() {
    scanf("%d", &n);
    int three = 0, two = 0;
    for (int i = 1 ; i <= n ; i ++) {
        int a;
        scanf("%d", &a);
        d[a].push_back(i);
    }
    vector<int> ind2, ind3;
    for (int i = 1 ; i <= 2000 ; i ++) {
        if (d[i].size() == 2) {
            ind2.push_back(i);
        }
        else if (d[i].size() >= 3) {
            ind3.push_back(i);
        }
    }
    if (ind2.size() <= 1 && ind3.size() <= 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 1 ; i <= 2000 ; i ++) {
        for (int j = 0 ; j < d[i].size() ; j++)
            printf("%d ", d[i][j]);
    }
    puts("");
    if (ind2.size() >= 2) {
        for (int i = 1 ; i <= 2000 ; i ++) {
            if (i == ind2[0]) {
                reverse(d[i].begin(), d[i].end());
            }
            for (int j = 0 ; j < d[i].size() ; j++)
                printf("%d ", d[i][j]);
        }
        puts("");
        for (int i = 1 ; i <= 2000 ; i ++) {
            if (i == ind2[1]) {
                reverse(d[i].begin(), d[i].end());
            }
            for (int j = 0 ; j < d[i].size() ; j++)
                printf("%d ", d[i][j]);
        }
        puts("");
        
    } else {
        for (int i = 1 ; i <= 2000 ; i ++) {
            if (i == ind3[0]) {
                swap(d[i][0], d[i][1]);
            }
            for (int j = 0 ; j < d[i].size() ; j++)
                printf("%d ", d[i][j]);
        }
        puts("");
        for (int i = 1 ; i <= 2000 ; i ++) {
            if (i == ind3[0]) {
                swap(d[i][0], d[i][2]);
            }
            for (int j = 0 ; j < d[i].size() ; j++)
                printf("%d ", d[i][j]);
        }
        puts("");
    }
    
    return 0;
}