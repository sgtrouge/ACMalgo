#include <iostream>
#include <algorithm>

using namespace std;
vector <int> adj[100001];
int a[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n-1; i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
}