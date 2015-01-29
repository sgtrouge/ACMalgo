#include <iostream>
#include <math.h>
using namespace std;

int d[2000005];
int main()
{	
	string a, b;
	cin >> a >> b;
	string s = b+a;
	int r = 0;	int l = 0;
	for (int i = 1; i < s.length(); i++)
	{
		int k;
		if (i > r) k = 1;
		else k = min(d[i-l], r-i+1)+1;
		while ((i+k-1 < s.length()) && (s[k-1] == s[i+k-1])) k++;
		k--;		d[i] = k;
		if (i + k -1  > r) 
		{
			r = i+k-1;
			l = i;
		}
			if ((d[i] >= b.length()) && (i >= b.length()))
			cout << i-b.length()+1 << " ";
	}	
	cout << endl;
}
