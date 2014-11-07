#include <iostream>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;
int b[6];
int tmp[6];
int co;
int a[20000][6];
void gen(int pos, int rem)
{
	if (pos == 6) 
	{
		if (rem == 0) 
		{
			for (int i = 0; i < 6; i++) a[co][i] = tmp[i];
			co++;
		}
		return;
	}
	for (int i = 0; i <= rem; i++)
	{
		tmp[pos] = i;
		gen(pos+1, rem-i);
	}	
}

bool same(int a[6], int b[6])
{
	for (int i = 0; i < 6; i++) if (a[i] != b[i]) return false;
	return true;
}
int main()
{
	gen(0, 15);
	int test = 0;
	while (true)
	{
		test++;
		char c;
		cin >> c;
		if (c == 'e') return 0;
		cout << "Case " << test << ": ";
		if (c == 'm')
		{
			for (int i = 0; i < 6; i++) cin >> b[i];
			for (int j = 0; j < co; j++)
			{
				if (same(a[j], b))
				{
					cout << j << endl;
					break;
				}
			}
		}
		else
		{
			int ind;
			cin >> ind;
			for (int i = 0; i < 6; i++) cout << a[ind][i] << " ";
			cout << endl;
		}
	}
}