#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool comp(int a[26], int b[26])
{
	for (int i = 0; i < 26; i++) 
		if (a[i] != b[i]) return false;
	return true;
}
int main()
{
	int t;
	int co1[26];
	int co2[26];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int res = 0;
		string s;
		cin >> s;
		for (int i = 0; i < s.size()-1; i++)
		{
			for (int j = i+1; j < s.size(); j++)
			{
				for (int z = 0; z < 26; z++)
				{
					co1[z] = 0;
					co2[z] = 0;
				}
				for (int k = 0; k < s.size(); k++)
				{
					if (j + k >= s.size())					break;
					co1[s[i+k] - 97]++;
					co2[s[j+k] - 97]++;
					if (comp(co1, co2)) res++;
				}
			}	
		}
		cout << res << endl;
	}
	return 0;
}