#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>


using namespace std;


const int N = (int)1e5 + 100;

int v[256];

//char s[N];
string s;

//multiset<long long> ms;
map<long long, long long> ms;
int n;

int main() {
    for (char c = 'a' ; c <= 'z' ; c ++) {
        cin >> v[c];
    }
    //scanf("%s", s);
    //n = strlen(s);
    cin >> s;
    n = s.length();
    long long ans = 0;
    for (char c = 'a' ; c <= 'z' ; c ++) {
        ms.clear();
        long long currentSum = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (s[i] == c) {
                ms[currentSum] ++;
            }
            currentSum += v[s[i]];
        }
        /*
        for (multiset<long long>::iterator it = ms.begin() ; it != ms.end() ; it++)
            cout << *it <<  ' ';
        cout << endl;
        */
        currentSum = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (s[i] == c) {
                //ms.erase(ms.find(currentSum));
                int left = --ms[currentSum];
                if (left == 0)
                    ms.erase(currentSum);
                ans += ms[currentSum + v[c]];
                
            }
            currentSum += v[s[i]];
        }
        //cout << "ans = " << ans << endl;
    }
    cout <<  ans << endl;
    return 0;
}