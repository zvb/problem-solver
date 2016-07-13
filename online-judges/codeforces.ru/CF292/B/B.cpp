#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1 << 30;
const int N = 2005;

char g[N][N];
int d[N][N];

int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<int> gr[N*N];
int color[N*N];

int ok = 1;



void put(int p, int q) {
	if (p > q)
		swap(p, q);
	//cout << "connectin " << p << ' ' << q << endl;
	if (q - p == 1) {
		int ii = p/m + 1, jj = p%m + 1;
		g[p/m + 1][p%m + 1] = '<';
		g[q/m + 1][q%m + 1] = '>';
	} else {
		int ii = p/m + 1, jj = p%m + 1;
		g[p/m + 1][p%m + 1] = '^';
		g[q/m + 1][q%m + 1] = 'v';
	}
}

int deg[N*N];

priority_queue<pair<int, int> > q;


int main() {
	scanf("%d%d\n", &n, &m);
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%s\n", g[i] + 1);
		for (int j = 1 ; j <= m ; j++) {
			d[i][j] = (int)(g[i][j] == '.');
		}
	}
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= m ; j++) {
			if (d[i][j] == 1) {
				for (int k = 0 ; k < 4 ; k ++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (d[ni][nj] == 1) {
						int from = (i - 1) * m + j - 1;
						int to = (ni - 1) * m + nj - 1;

						gr[from].push_back(to);
						deg[from] ++;
					}
				}
			}
		}
	}
	/*for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ;j <= m ; j ++) {
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}*/
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j ++) {
			int v = (i - 1) * m + j - 1;
			if (d[i][j] == 1) {
				q.push(make_pair(-deg[v], v));
				//cout << v << ' ' << deg[v] << endl;
			}
		}
	}

	while (!q.empty()) {
		int curDeg = -q.top().first;
		int curV = q.top().second;
		q.pop();
		if (deg[curV] != curDeg) continue;
		if (curDeg >= 2) {
			ok = 0;
			break;
		}
		//cout << "curV = " << curV << " curdeg " << curDeg << endl;
		int i = curV / m + 1, j = curV % m + 1;
		int localOk = 0;
		for (int k = 0 ; k < 4 ; k ++) {
			int ni = i + dx[k], nj = j + dy[k];
			int nv = (ni - 1) * m + nj - 1;
			if (d[ni][nj] == 1 && deg[nv] >= 1) {
				put(curV, nv);
				localOk = 1;
				for (int dir = 0 ; dir < 4; dir ++) {
					int x = (i + dx[dir] - 1) * m + j + dy[dir] - 1;

					int &ref = deg[x];
					if (ref > 0) {
						ref --;
						if (ref > 0)
							q.push(make_pair(-ref, x));
					}
				}
				for (int dir = 0 ; dir < 4; dir ++) {
					int x = (ni + dx[dir] - 1) * m + nj + dy[dir] - 1;
					int &ref = deg[x];
					if (ref > 0) {
						ref --;
						if (ref > 0)
							q.push(make_pair(-ref, x));
					}
				}
				deg[curV] = deg[nv] = 0;

				break;
			}
		}
		if (!localOk)
			ok = 0;
	}

	
	if (!ok) {
		puts("Not unique");
		return 0;
	}
	for (int i = 1 ; i <= n ; i ++) {
		puts(g[i] + 1);
	}

	return 0;
}