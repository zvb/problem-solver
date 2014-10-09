#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

string s = "+------------------------+";

char p[100][100];

int main() {
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int ii = 1, jj = 1;
    int n;
    scanf("%d", &n);
    while (jj < 12) {
        if (n > 0)
            p[ii][jj] = 'O';
        else
            p[ii][jj] = '#';
        ii ++;
        if (ii == 5) {
            ii = 1;
            jj ++;
        }
        else if (ii == 3 && jj > 1) {
            p[ii][jj] = '.';
            ii = 4;
        }
        n --;
    }
    cout << s << endl;
    for (int i = 1 ; i <= 4 ; i ++) {
        printf("|");
        for (int j = 1 ; j <= 11 ; j ++) {
            if (p[i][j])
                printf("%c.", p[i][j]);
            else
                printf("#.");
        }
        if (i == 1 )
            puts("|D|)");
        else if (i == 3)
            puts("..|");
        else if (i == 2)
            puts("|.|");
        else
            puts("|.|)");
    }
    cout << s << endl;
    
    
    return 0;
}
