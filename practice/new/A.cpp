#include <iostream>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;
int a[20][3];
int n;

int countbit (long long i)
{
	int co = 0;
	for (int j = 0; j < n; j++) 
	{
		if (i & (1 << j)) co++;
	}
	return co;
}
int main()
{
	int res;
	int test = 0;
	while (true)
	{
		cin >> n;
		if (n == 0) return 0;
		res = 1;
		vector <pair<int, int> > dp[3000];
		for (int i = 0; i < n; i++)			
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			sort(a[i], a[i]+3);
		}
		for (int i = 0; i < n; i++) 		dp[1 << i].push_back(make_pair(a[i][1], a[i][2]));
		for (int i = 0; i < (1 << n); i++) 	
		{
			if (dp[i].size() == 0) continue;
			int tmp = countbit(i);
			res = max(res, tmp);
			for (int j = 0; j < n; j++)
			{
				if ( (i | (1 << j) ) != i)
				{
					for (int k = 0; k < dp[i].size(); k++)
					{
						if ((a[j][1] <= dp[i][k].first) && (a[j][2] <= dp[i][k].second))
						{
							dp[i | (1 << j)].push_back(make_pair(a[j][1], a[j][2]));
						}
						else
						{
							if ((a[j][0] <= dp[i][k].first) && (a[j][1] <= dp[i][k].second))
							{
								dp[i | (1 << j)].push_back(make_pair(a[j][0], a[j][1]));
							}
							if ((a[j][0] <= dp[i][k].first) && (a[j][2] <= dp[i][k].second))
							{
								dp[i | (1 << j)].push_back(make_pair(a[j][0], a[j][2]));
							}
						}
					}
				}
			}
		}
		test++;
		cout << "Case " << test << ": " << res << endl;
	}
	return 0;
}