#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int n, m;
string s;

map<char,int> c;

int w, b;

int main() {
    c['Q'] = c['q'] = 9;
    c['R'] = c['r'] = 5;
    c['B'] = c['b'] = 3;
    c['N'] = c['n'] = 3;
    c['P'] = c['p'] = 1;
    c['K'] = c['k'] = c['.'] = 0;
    
    //cout << c['Q'] << endl;
    
    for (int i = 0 ; i < 8 ;  i++) {
        getline(cin, s);
        //cout << "s = " << s << endl;;
        for (int j = 0 ; j < 8 ; j ++) {
            if (s[j] <= 'z' && s[j] >= 'a')
                b += c[s[j]];
            else
                w += c[s[j]];
        }
    }
    //cout << w << ' ' << b << endl;
    if (w > b) {
        cout << "White\n";
    } else if (w < b) {
        cout << "Black\n";
    } else {
        cout << "Draw\n";
    }
    return 0;
}