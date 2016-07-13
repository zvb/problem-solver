#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

const int N = 50;

int a[N][N];
int visited[N][N];
queue<pair<int, int> > q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n;

bool ok(int x, int y) {
	return x >= 1 && y >= 1 && x <= n && y <= n && !visited[x][y] && !a[x][y];
}

int main() {
	scanf("%d ", &n);
	for (int i = 1 ; i <= n ; i ++) {
		string s;
		getline(cin, s);
		for (int j = 0 ; j < s.length() ; j++) {
			if (s[j] == '.') {
				a[i][j+1] = 0;
			} else {
				a[i][j+1] = 1;
			}
		}
	}

	q.push(make_pair(1, 1));
	while (!q.empty()) {
		pair<int, int> f = q.front(); q.pop();
		int x = f.first, y = f.second;
		for (int k = 0 ; k < 4 ; k++) {
			int xNext = x + dx[k], yNext = y + dy[k];
			if (ok(xNext, yNext)) {
				visited[xNext][yNext] = 1;
				//cerr << "visiting " << xNext << ' ' << yNext << endl;
				q.push(make_pair(xNext, yNext));
			}
		}
	}
	if (!visited[n][n]) {
		q.push(make_pair(n, n));
		while (!q.empty()) {
			pair<int, int> f = q.front(); q.pop();
			int x = f.first, y = f.second;
			for (int k = 0 ; k < 4 ; k++) {
				int xNext = x + dx[k], yNext = y + dy[k];
				if (ok(xNext, yNext)) {
					visited[xNext][yNext] = 1;
					//cerr << "visiting " << xNext << ' ' << yNext << endl;
					q.push(make_pair(xNext, yNext));
				}
			}
		}
	}
	

	int walls = 0;
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= n ; j ++) {
			if (visited[i][j]) {
				for (int k = 0 ; k < 4 ; k++) {
					int ii = i + dx[k], jj = j + dy[k];
					if (!visited[ii][jj]) {
						// see wall
						walls ++;
					}
				}
			}
		}
	}
	if (n > 1)
		walls -= 4;
	printf("%d\n", walls * 9);
	return 0;
}