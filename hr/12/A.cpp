#include <algorithm>
#include <iostream>
using namespace std;
long long a[200000];
int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)		cin >> a[i];
	sort(a,a+n);
	int res = 0;		int r = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < r) continue;
		res = res+1;
		while ((r < n) && (a[r] <= a[i]+4))
		{
			r++;
		}
		if (r >= n) break;
	}
	cout << res << endl;
}