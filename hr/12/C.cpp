#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
long long a[100005];
int main()
{
	int n;
	long long res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	long long l = 1; 		long long r = 100005;
	while (l <= r)
	{
		long long mid = (l+r)/2;
		bool check = true;
		long long tmp = mid;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > tmp) tmp = tmp - (a[i] - tmp);
			else			tmp = tmp + (tmp - a[i]);
			if (tmp < 0) 
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			res = mid;
			r = mid -1;
		}
		else	l = mid+1;
	}
	cout << res << endl;
}