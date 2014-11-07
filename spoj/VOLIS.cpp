#include <iostream>
#include <cstdio>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
long long a[6000];
long long b[6000];
long long p[6000];
pair<long long, int> trueval[6000]; // true value of sorted b
long long dp[6000];
long long BIT[2][6000]; // 1:Check for stuff < number, 2: otherwise
int n,m;

void update(int u, int base, long long gt, int tree)
{
	if (u > m) return;
	int k = u-1;
	if (tree == 1) k = m-u;
	BIT[tree][u] = max(BIT[tree][u], gt + abs(trueval[k].first - trueval[base-1].first));
	update(u + (u & -u), base, gt, tree);
}

long long find(int u, int tree)
{
	if (u <= 0) return 0;
	int k = u-1;	if (tree == 1) k = m-u;
	int t = (u - (u & -u));
	int tp = t-1;	if (tree == 1) tp = m-t;
	long long tmp = -1;
	if (t > 0)
	{
		tmp = find(t, tree);
		if (tmp != -1)			tmp = tmp + abs(trueval[k].first - trueval[tp].first);
	}
	tmp = max(tmp, BIT[tree][u]);
	return tmp;
}

int main()
{
	cin >> n >> m;
	bool check[m];
	for (int i = 0;  i < m; i++) 	check[i] = false;
	long long res = 0;
	for (int i = 0;  i < n; i++)	cin >> a[i];
	for (int i = 0;  i < m; i++) 	cin >> b[i];
	for (int i = 0;  i < m; i++)
	{
		trueval[i].first = b[i];
		trueval[i].second = i;
	}
	sort(trueval, trueval + m);
	for (int i = 0; i < m; i++)		p[trueval[i].second] = i;
	for (int i = 0; i < n; i++)
	{
		for (int l = 0; l < 2; l++)
		for (int r = 1; r <= n; r++) BIT[l][r] = -1;
		for (int j = 0; j < m; j++)
		{	
			//Insert old DP
			if (check[j]) 
			{
				update(p[j]+1, p[j]+1, dp[j], 0);
				update(m-p[j], p[j]+1, dp[j], 1);
			}
			if (a[i] == b[j])
			{
				dp[j] = max(dp[j], find(p[j]+1, 0));
				dp[j] = max(dp[j], find(m-p[j], 1));
				check[j] = true;
				res = max(res, dp[j]);
			}
		}
	}
	cout << res << endl;
	return 0;
}