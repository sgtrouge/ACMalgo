#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int n;
int countt;
int pos[100000];
int a[100000];

int solve()
{
	bool swap = false;
	countt = 0;
	cin >> n;
	fill(a,a+n,-1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == i)
		{
			 countt++;
		}
		else
		{
			if (a[a[i]] == i)
			{
			  swap = true;
			}
		}
	}
	if (swap) return countt + 2;
	if (countt == n) return n;
	if (countt < n) return countt + 1;
}
int main()
{
	cout << solve() << endl;
}
