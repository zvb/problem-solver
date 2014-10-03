#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int mp[10];

int l[6];

int main() {
    for (int i = 0 ; i < 6 ; i ++) {
        scanf("%d", &l[i]);
        mp[l[i]] ++;
    }
    int legs = 0;
    for (int i = 0 ; i < 10 ;i ++) {
        if (mp[i] >= 4) {
            mp[i] -= 4;
            legs = 1;
        }
    }
    if (!legs) {
        puts("Alien");
        return 0;
    }
    for (int i = 0 ; i < 10 ; i ++) {
        if (mp[i] == 1) {
            puts("Bear");
            return 0;
        } else if (mp[i] == 2) {
            puts("Elephant");
            return 0;
        }
    }
    

    return 0;
}