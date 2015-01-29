#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		int n,m;
		cin >> n >> m;
		long long p[n][m];
		long long b[n][m];
		for (int l = 0; l < n; l++)
			for (int k = 0; k < m; k++) cin >> p[l][k];
		for (int l = 0; l < n; l++)
			for (int k = 0; k < m; k++) cin >> b[l][k];
		long long res = 0;
		long long rem = 0;
		for (int i = n-1; i >= 0; i--)
		{
			for (int j = 0; j < m; j++)
			{
				if 
			}
		}
		t--;
	}
	return 0;
}