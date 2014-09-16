#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int w[100];

int main() {
    srand(1ll * clock() * (time(0) % 7 + 1));
    int W = 0;
    
    int n = 10;
    for (int i = 0 ; i < n ; i ++) {
        w[i] = rand()%15;
        W += w[i];
    }
    printf("%d\n", (rand()%W + W)%W);
    printf("%d\n", n);
    for (int i = 0 ; i < n ; i ++)
        printf("%d ", w[i]);
    puts("");
    
    return 0;
}