#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> a;
const long long maxN = 2000000001;
int main()
{
	long long n, l, x, y; 
	cin >> n >> l >> x >> y;
	for (int i = 0; i < n; i++) 
	{
		long long tmp; 	cin >> tmp;		a.push_back(tmp);
	}
	bool cx = false;
	bool cy = false;
	long long check = maxN;	
	for (int i = 0; i < n; i++)
	{
		long long tmp = a[i] - x; 
		if (binary_search(a.begin(), a.end(), tmp)) cx = true;
		tmp = a[i] + x; 
		if (binary_search(a.begin(), a.end(), tmp)) cx = true;
		tmp = a[i] - y; 
		if (binary_search(a.begin(), a.end(), tmp)) cy = true;
		tmp = a[i] + y; 
		if (binary_search(a.begin(), a.end(), tmp)) cy = true;
	}
	if (cx && cy) 				{cout << 0 << endl;		return 0;}
	else // Where answer = 1 or 2 
	{
		if (cx) 			{cout << 1 << endl << y << endl; 	return 0;}
		if (cy)				{cout << 1 << endl << x << endl; 	return 0;}
		for (int i = 0; i < n; i++)
		{
			long long tmp = a[i] - x; 
			if ((tmp > 0) && (tmp <= l))
			{
			if (binary_search(a.begin(), a.end(), tmp - y)) check = tmp;
			if (binary_search(a.begin(), a.end(), tmp + y)) check = tmp;
			}
			tmp = a[i] + x; 
			
			if ((tmp > 0) && (tmp <= l))
			{
			if (binary_search(a.begin(), a.end(), tmp - y)) check = tmp;
			if (binary_search(a.begin(), a.end(), tmp + y)) check = tmp;
			}
			tmp = a[i] - y; 
			
			if ((tmp > 0) && (tmp <= l))
			{
			if (binary_search(a.begin(), a.end(), tmp - x)) check = tmp;
			if (binary_search(a.begin(), a.end(), tmp + x)) check = tmp;
			}
			tmp = a[i] + y; 
			if ((tmp > 0) && (tmp <= l))
			{
			if (binary_search(a.begin(), a.end(), tmp - x)) check = tmp;
			if (binary_search(a.begin(), a.end(), tmp + x)) check = tmp;
			}
		}
		if (check != maxN) 				{cout << 1 << endl << check << endl; return 0;};
		cout << 2 << endl << x << " " << y << endl;
	}
	return 0;
}