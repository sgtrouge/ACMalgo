#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int a[300];
vector <int> b;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	for (int i = n-1; i >= 0; i--)
	{
		bool choose = true;
		for (int j = 0; j < b.size(); j++)
		{
			if ((b[j] % a[i]) == 0) 
			{
				choose = false;
				break;
			}
		}
		if (choose == false) continue;
		b.push_back(a[i]);
	}
	cout << b.size() << endl;
	for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
	cout << endl;
	return 0;
}