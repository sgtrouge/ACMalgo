#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <map>
using namespace std;
const long long maxbound = 60000000;
map<long long, long long> BIT;
int n, res;

long long a[60000];

int find(long long ind)
{
	if (ind <= 0) return 0;
	return BIT[ind] + find(ind - (ind & -ind));
}

void update(long long ind)
{
	if (ind > maxbound) return;
	BIT[ind]++;
	update(ind + (ind & -ind));
}
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void solve()
{
	for (int i = n-1; i >= 0; i--)
	{
		res = res + find(a[i]-1);
		update(a[i]);
	}
	cout << res << endl;
}

int main()
{
	input();
	solve();
}


