#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const long long module = 1000000007;
long long dp[6000];
long long sum[6000];
int main()
{
	long long n, a, b, k;
	cin >> n >> a >> b >> k;
	dp[a] = 1;
	for (int rz = 1; rz <= k; rz++)
	{
		for (int i = 1; i <= n; i++) sum[i] = (sum[i-1]+dp[i]) % module;
		for (long long i = 1; i <= n; i++)
		{
			dp[i] = 0;
			if (i == b) continue;
			long long z = ((sum[i] - sum[i-1]) + module) % module;
			if (i < b) 
			{
				int r = (i + b + 1)/ 2-1;
				dp[i] = (sum[r] - z + module) % module;
			}
			else
			{
				int l = (i + b)/2 + 1;
				dp[i] = (sum[n] - sum[l-1] - z + 2*module) % module;
			}
		}
	}
		for (int i = 1; i <= n; i++) sum[i] = (sum[i-1]+dp[i]) % module;
		cout << sum[n] << endl;
		//for (int i = 1; i <= n; i++) cout << dp[i] << " ";
		//cout << endl;
}