#include <iostream>
#include <set>
#include "math.h"
#include <vector> 
using namespace std;
int n,m,d, res;
vector <int> adj[100001];
bool check[100001];
set <pair<int ,int> > nextdist[100001];

void put(int u, int v, int nextdist_child) {
	nextdist[u].insert(make_pair(nextdist_child, v));
	if (nextdist[u].size() > 2) { 
		nextdist[u].erase(nextdist[u].begin());
	}
}

int pick(int u, int v) {
	for (auto it = nextdist[u].rbegin(); it != nextdist[u].rend(); it++) {
		if (it->second != v) return it->first;
	}
	return -1;
}

int dfs1(int u, int p) {
	if (check[u]) put(u, u, 0);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		int nextdist_child = dfs1(v,u);
		if (nextdist_child > 0) 
			put(u, v, nextdist_child);
	}
	if (nextdist[u].size() > 0) {
		return nextdist[u].rbegin()->first + 1;
	} else {
		return 0;
	}
}

void dfs2(int u, int p, int prev) {
	int maxdist = max(0, prev);
	if (nextdist[u].size() > 0) 
		maxdist = max(maxdist, nextdist[u].rbegin()->first);
	if ((maxdist <= d)) {
		res++;
 	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		int nextdistdist;
		if (prev == 0) nextdistdist = -1; 
		else 		   nextdistdist = prev;
		nextdistdist = max(nextdistdist, pick(u, v));
		dfs2(v, u, nextdistdist + 1);	
	}
}

int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		check[temp] = true;
	}
	for (int i = 0; i < n-1; i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0,0);
	cout << res << endl;
}