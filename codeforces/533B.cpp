#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector <int> adj[200001];
long long eff[200001];
int n, root;

pair<long long, long long> dfs(int u) {
	long long maxodd  = -1;
	long long maxeven = 0; 
	for (int i = 0; i < adj[u].size(); i++) {
		long long nextodd = maxodd;
		long long nexteven = maxeven;
		int v = adj[u][i];
		pair<long long, long long> tempres = dfs(v);
		nextodd = max(nextodd, maxeven + tempres.first);
		if (maxodd != -1) {
			nextodd = max(nextodd, maxodd + tempres.second);
			nexteven = max(nexteven, maxodd + tempres.first);
		}
		nexteven = max(nexteven, maxeven + tempres.second);
		maxodd = nextodd;
		maxeven = nexteven;
	}
	maxodd = max(eff[u] + maxeven, maxodd);
	return make_pair(maxodd, maxeven);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int pi, f;
		cin >> pi >> f;
		eff[i] = f;
		if (pi == -1) {
			root = i;
			continue;
		} 
		adj[pi].push_back(i);
	}
	pair<long long, long long> res = dfs(root);
	cout << max(res.first, res.second) << endl;
}