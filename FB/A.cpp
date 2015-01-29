#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int r = 0; r < t; r++)
	{
		string s;
		cin >> s;
		string smin = s;
		string smax = s;
		for (int i = 0; i < s.size(); i++)
		{
			int l = i;
			for (int j = i+1; j < s.size(); j++)
			{
				if (((i == 0) &&(s[j] != '0') && (s[j] < s[i]))
				|| ((i != 0) && (s[j] < s[i])))
				{
					if (s[j] < s[l]) l = j;
				}
			}
			if (l != i)
			{
				char tmp = smin[l];
				smin[l] = smin[i];
				smin[i] = tmp;
				break;
			}
		}
		for (int i = 0; i < s.size(); i++)
		{
			int l = i;
			for (int j = i+1; j < s.size(); j++)
			{
				if (((i == 0) &&(s[j] != '0') && (s[j] > s[i]))
				|| ((i != 0) && (s[j] > s[i])))
				{
					if (s[j] > s[l]) l = j;
				}
			}
			if (l != i)
			{
				char tmp = smax[l];
				smax[l] = smax[i];
				smax[i] = tmp;
				break;
			}
		}		
		cout << "Case #" << r+1 << ": " << smin << " " << smax << endl;
	}
}