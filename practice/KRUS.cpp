#include <iostream>
#include <cstdio>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
struct edge
{
	int u,v,value;
};

int n,m,res;
edge a[100001];
int r[3001];
vector < pair<int, int> > lis[100001];
bool cmpedge(edge a, edge b)
{
	return (a.value < b.value);
}

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].value;
	}
	memset(r, -1, sizeof(r));
}

int root(int a)
{
	while (r[a] > 0) a = r[a];
	return a;
}

void unite(int a, int b)
{
	if (r[a] < r[b])
	{
		r[a] = r[a] + r[b];
		r[b] = a;
	}
	else
	{
		r[b] = r[a] + r[b];
		r[a] = b;
	}
}

void krus()
{
	for (int i = 0; i < m; i++)
	{
		int u = root(a[i].u);
		int v = root(a[i].v);
		if (u != v) 
		{
			unite(u,v);
			lis[a[i].u].push_back(make_pair(a[i].v, a[i].value));
			lis[a[i].v].push_back(make_pair(a[i].u, a[i].value));
		}	
	}
}

bool dfs(int bef, int u, int target)
{
	if (u == target) return true;
	int si = lis[u].size();
	for (int i = 0; i < si; i++)
	{
		if (bef == lis[u][i].first) continue;
		bool tmp = dfs(u, lis[u][i].first, target);
		if (tmp) 
		{
			res = max(res,lis[u][i].second);
			return true;
		}
	}	
	return false;
}

void solve()
{
	int com, u, v;
	cin >> com;
	for (int i = 0; i < com; i++)
	{
		cin >> u >> v;
		res = 0;
		dfs(-1,u,v);
		cout << res << endl;
	}
}

int main()
{
	input();
	sort(a,a+m,cmpedge);
	krus();
	solve();
}
