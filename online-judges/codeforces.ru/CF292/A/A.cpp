#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int inf = 1 << 30;
const int N = 100;




int n;
int d[N];
string str;
//         0  1  2  3  4  5  6  7  8  9
int p[] = {0, 1, 2, 3, 3, 5, 5, 7, 7, 7};
vector<int> nd;

int main() {
	scanf("%d ", &n);
	cin >> str;
	for (int i = 0 ; i < n ; i ++) {
		d[i + 1] = str[i] - '0';
	}

	for (int i = 1 ; i <= n ; i ++) {
		int mxp = p[d[i]];
		if (mxp >= 2) {
			nd.push_back(mxp);
			int rest = 1;
			for (int j = mxp + 1 ; j <= d[i] ; j++) {
				rest *= j;
			}
			if (rest > 1) {
				int r = rest;
				for (int dv = 2 ; dv <= 3 ; dv ++) {
					while (r % dv == 0) {
						r /= dv;
						nd.push_back(dv);
					}
				}
			}
		}

	}
	sort(nd.begin(), nd.end(), std::greater<int>());
	for (int i = 0 ; i < nd.size(); i ++)
		printf("%d", nd[i]);
	puts("");

	return 0;
}