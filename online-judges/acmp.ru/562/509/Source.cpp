#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>


using namespace std;

const int p = 127;

struct State
{
	int depth;
	State() {
		data[0].resize(4);
		data[1].resize(4);
		depth = 0;
	}
	vector<int> data[2];
	long long get_hash() {
		long long hash = 0;
		for (int i = 0 ; i < 2;  i++) {
			for (int j = 0 ; j < data[i].size() ; j++) {
				hash = (hash * p + data[i][j]);
			}
		}
		return hash;
	}
	void read_state() {
		string str;
		getline(cin, str);
	    for (int i = 0 ; i < 4 ; i++) {
	    	data[0][i] = str[i];
	    }
	    getline(cin, str);
	    for (int i = 0 ; i < 4 ; i++) {
	    	data[1][i] = str[i];
	    }
	}
};

int n, m;

State s, t;

queue<State> q;

const int dx[] = {-1,  0, 1, 0};
const int dy[] = { 0, -1, 0, 1};

set<long long> used;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    s.read_state();
    t.read_state();

    
    q.push(s);
    while (!q.empty()) {
    	State cur = q.front(); q.pop();
		long long hash = cur.get_hash();
		if (t.get_hash() == hash) {
			printf("%d\n", cur.depth);
			return 0;
		}

    	int posi, posj;
    	for (int i = 0 ; i < 2 ; i ++) {
    		for (int j = 0 ; j < 4 ; j++) {
    			if (cur.data[i][j] == '#')
    				posi = i, posj = j;
    		}
    	}
    	//cout << "posi, posj = " << posi << ' ' << posj << endl;
    	for (int k = 0 ; k < 4 ; k++) {
    		int ni = posi + dx[k], nj = posj + dy[k];
    		if (0 <= ni && ni < 2 && 0 <= nj && nj < 4) {
    			swap(cur.data[posi][posj], cur.data[ni][nj]);
    			cur.depth ++;
    			long long hash = cur.get_hash();
    			if (used.count(hash) == 0) {
    				
    				used.insert(hash);
    				q.push(cur);
    			}
    			swap(cur.data[posi][posj], cur.data[ni][nj]);
    			cur.depth --;
    		}
    	}
    }
    puts("-1");
    return 0;
}


















