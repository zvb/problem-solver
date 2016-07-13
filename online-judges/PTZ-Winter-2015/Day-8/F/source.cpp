#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>


using namespace std;

#define filename ""

const int N = (int)1e3 + 100;


int color[N], isColoredSuc[N];
int parent[N];

vector<int> g[N];
int n;

const int root = 1;

void dfs(int v, int p = -1) {
    for (int i = 0 ; i < g[v].size(); i ++) {
        int to = g[v][i];
        if (to != p) {
            dfs(to, v);
            parent[to] = v;
        }
    }
}


int main() {

    scanf("%d", &n);
    for (int i = 1 ; i < n ; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(root, -1);
    
    color[root] = 1;
    cout << root << ' ' << color[root] << endl;
    while (1) {
        int v, c;
        cin >> v >> c;
        if (v < 0)
            break;
        color[v] = c;
        int currentNode = v;
        
        currentNode = parent[currentNode];
        while (currentNode != root && !isColoredSuc[currentNode]) {
            //cout << "looking colored suc " << currentNode << endl;
            currentNode = parent[currentNode];
        }
        //cout << "currentNode " << currentNode << endl;
        if (color[currentNode]) {
            int targetNode = -1;
            for (int i = 1 ; i <= n ; i ++) {
                if (color[parent[i]] > 0 && color[i] == 0) {
                    targetNode = i;
                    break;
                }
            }
            assert(targetNode != -1);
            
            set<int> neiboringColors;
            for (int i = 0 ; i < g[targetNode].size() ; i++) {
                int to = g[targetNode][i];
                if (color[to]) {
                    neiboringColors.insert(color[to]);
                }
            }
            assert(neiboringColors.size() < 4);
            int targetColor = -1;
            for (int i = 1 ; i <= 4; i++) {
                if (neiboringColors.count(i) == 0) {
                    targetColor = i;
                    break;
                }
            }
            
            
            color[targetNode] = targetColor;
            
            int vv = targetNode;
            do {
                vv = parent[vv];
                isColoredSuc[vv] = 1;
            } while (vv != root);
            
            cout << targetNode << ' ' << targetColor << endl;
        } else {
            //cout << "here " << endl;
            set<int> neiboringColors;
            for (int i = 0 ; i < g[currentNode].size() ; i++) {
                int to = g[currentNode][i];
                if (color[to]) {
                    neiboringColors.insert(color[to]);
                }
            }
            assert(neiboringColors.size() < 4);
            int targetColor = -1;
            for (int i = 1 ; i <= 4; i++) {
                if (neiboringColors.count(i) == 0) {
                    targetColor = i;
                    break;
                }
            }
            //cout << "target Color = " << targetColor << endl;
            color[currentNode] = targetColor;
            cout << currentNode << ' ' << targetColor << endl;
            do {
                currentNode = parent[currentNode];
                isColoredSuc[currentNode] = 1;
            } while (currentNode != root);
        }
        int vv = v;
        do {
            //cout << "marking " << vv << endl;
            vv = parent[vv];
            isColoredSuc[vv] = 1;
        } while (vv != root);
    }
    
    
    return 0;
}






