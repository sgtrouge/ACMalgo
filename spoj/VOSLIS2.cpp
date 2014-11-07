#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long dp[6000];
int main()
{
	int n,m;
	long long res = 0;
	vector <int> low;
	vector <int> gtlow;
	vector <int> high;
	vector <int> gthigh;
	long long a[6000];
	long long b[6000];
	bool check[6000];
	memset(check, false, sizeof(check));
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < n; i++)
	{
		low.clear();		gtlow.clear();
		high.clear();		gthigh.clear();
		for (int j = 0; j < m;	j++)
		{
			if ((check[j])|| (a[i] == b[j]))
			{
				long long tmp = dp[j];
				
				if (check[j])
				{
				while ((low.size() > 0) && (b[j] <= low[low.size()-1]))
				{
					tmp = gtlow[low.size()-1] + abs(low[low.size()-1] - b[j]);
					low.pop_back();		gtlow.pop_back();
				}
				while ((low.size() > 0) && (tmp > gtlow[low.size()-1] + abs(low[low.size()-1] - b[j])))
				{
					low.pop_back();		gtlow.pop_back();
				}
				low.push_back(b[j]);
				gtlow.push_back(tmp);
				}
				
				res = max(res, tmp);
				tmp = 0;
				
				if (check[j])
				{
				while ((high.size() > 0) && (b[j] >= high[high.size()-1]))
				{
					tmp = gthigh[high.size()-1] + abs(high[high.size()-1] - b[j]);
					high.pop_back();		gthigh.pop_back();
				}
				while ((high.size() > 0) && (tmp > gthigh[high.size()-1] + abs(high[high.size()-1] - b[j])))
				{
					high.pop_back();		gthigh.pop_back();
				}
				high.push_back(b[j]);
				gthigh.push_back(tmp);	
				}
				
				check[j] = true;	
				dp[j] = tmp;	
			}		
		}
	}
}