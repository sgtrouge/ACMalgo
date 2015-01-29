#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector <int> a[100005];
int n,m,num;
int low[100005];
int r[100050];
int rescut, resbridge;

void dfs(int u, int p)
{
	num++;	r[u] = num;	low[u] = num;
	int part = 0;		if (p != -1) part++;
	for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if (v == p) continue;
		if (r[v] == 0)
		{
			dfs(v,u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= r[u]) part++;
		}
		else	low[u] = min(low[u], r[v]);
	}
	if ((low[u] >= r[u]) && (p != -1)) resbridge++;
	if (part >= 2) 		rescut++;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u,v;
		cin >> u >> v;
		a[u].push_back(v);	a[v].push_back(u);
	}
	num = 0;
	for (int i = 1; i <= n; i++)
		if (r[i] == 0) dfs(i,-1);
	cout << rescut << " " << resbridge << endl;
}


