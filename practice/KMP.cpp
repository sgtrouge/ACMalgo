#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>

using namespace std;

string a,b;
char aa[1000001];
char bb[1000001];
int Z[1000000];
int res;
void Zfun()
{
	int j;
	for (int i = 0; i < b.length(); i++)
	{
		bb[i+1] = b[i];
	}
	for (int i = 0; i < a.length(); i++)
	{
		aa[i+1] = a[i];
	}
	Z[1] = 0;	
	for (int i = 2; i <= b.length(); i++)
	{
		j = i-1;
		do 
		{
			j = Z[j];
			if (bb[j+1] == bb[i]) 
			{
				Z[i] = j+1;
				break;
			}
			if (j == 0) break;
		} while (true);
	}
}

void search()
{
	int rb = 0;
	for(int i = 1; i <= a.length(); i++)
	{
		do
		{	
			if (aa[i] == bb[rb+1]) 
			{
				rb++;
				if (rb == b.length()) cout << i - rb + 1 << " ";
				break;
			}
			else
			{
				if (rb == 0) break;
				rb = Z[rb];
			}
		}while(true);	
	}
}

int main()
{
	cin >> a;
	cin >> b;
	Zfun();
	search();
	cout << endl;
	return 0;
}
