#include <iostream>
#include <vector>
#include <set>

using namespace std;
bool check[2001];
int a[1001];
int p[1001];
set <pair<int, pair<int, int>> > vert;


int root(int u) {
	while (p[u] != -1) {
		u = p[u];
	}
	return u;
}

void unite(int u, int v) {
	p[v] = u;
}
int main() {
	int n, m;
	int res = 0;
	int count = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = -1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v, g;
		cin >> u >> v >> g;
		vert.insert(make_pair(g, make_pair(u,v)));
	}

	for (auto it = vert.begin(); it != vert.end(); it++) {
		int u = it->second.first;
		int v = it->second.second;
		int g = it->first;
		int ru = root(u);
		int rv = root(v);
		if (rv == v) {
			p[v] = u;
			res += g;
			count++;
		}
	}
	if (count == n-1) {
		cout << res << endl;
	} else 	cout << -1 << endl;
	return 0;
}