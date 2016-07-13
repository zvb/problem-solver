#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0) + clock());
    long long n = (long long)1e18;
    long long k = rand()%100;
    cout << n << ' ' << k << endl;
    
    return 0;
}