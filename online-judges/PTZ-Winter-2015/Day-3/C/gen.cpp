#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int n = 5000;
	int m = 50;
	cout << n << endl;
	for (int i = 0 ; i < n ; i ++) {
		printf("%d ", m);
		for (int j = 0 ; j < m ; j ++)
			printf("%d ", rand()%m + 1);
	}
	return 0;
}
