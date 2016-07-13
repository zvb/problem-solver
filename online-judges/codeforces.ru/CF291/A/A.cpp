#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>


using namespace std;

#define filename ""

char str[20];
int s[20];

int main() {
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0 ; i < n ; i ++) {
    	s[i] = str[i] - '0';
    }
    for (int i = 0 ; i < n ; i ++) {
    	if (i == 0) {
    		if (s[i] != 9 && s[i] > 4)
    			s[i] = 9 - s[i];
    	} else {
    		if (s[i] > 4) {
    			s[i] = 9 - s[i];
    		}
    	}
    }
    for (int i = 0 ; i < n ; i++) {
    	printf("%d", s[i]);
    }
    puts("");
    
    
    return 0;
}
