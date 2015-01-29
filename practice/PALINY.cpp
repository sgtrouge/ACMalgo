#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
#include <assert.h>
using namespace std;

int od[100001];
int ev[100001];

int main()
{
	int n; cin >> n;
	string a;
	cin >> a;
	int r,l,j;
	int res = 0;
	r = -1;
	// do odd
	for (int i = 0; i < a.length(); i++)
	{
		if (i <= r)		 j = min(r-i, od[l+r-i])+1;
		else			 j = 1;
		while ((i-j >= 0) && (i+j < a.length()) && (a[i-j] == a[i+j]))	j++;
		j--;	od[i] = j;
		if (i + j > r)
		{
			r = i+j;
			l = i-j;
		}
		res = max(res, od[i]*2+1);
	}
	r = -1;
	// do even
	for (int i = 1; i < a.length(); i++)
	{
		if (i <= r)		 j = min(r-i+1, ev[l+r-i])+1;
		else			 j = 1;
		while ((i-j >= 0) && (i+j-1 < a.length()) && (a[i-j] == a[i+j-1]))	j++;
		j--;	ev[i] = j;
		if (i + j > r)
		{
			r = i+j-1;
			l = i-j;
		}
		res = max(res, ev[i]*2);
	}
	cout << res << endl;
}
