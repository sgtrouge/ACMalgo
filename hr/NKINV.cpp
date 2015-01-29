#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
int n, res;
int BIT[60001];
int a[60000];
using namespace std;

int find(int ind)
{
	if (ind <= 0) return 0;
	return BIT[ind] + find(ind - (ind & -ind));
}

void update(int ind)
{
	if (ind > 60000) return;
	BIT[ind]++;
	update(ind + (ind & -ind));
}
void input()
{
	n = 60000;
	for (int i = 0; i < n; i++)
	{
		a[i] = 60000-i;
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

