#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int n;
int a[500];

int lesser(int i, int j)
{
	return (i <= j);
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
}

void solve()
{
	cout << a[n-1] << " ";
	for (int i = 1; i <= n-2; i++)
		cout << a[i] << " ";
	cout << a[0] << endl;
}
int main()
{
	input();
	solve();
}
