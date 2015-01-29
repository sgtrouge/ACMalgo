#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long t,b,w,x,y,z;
	cin >> t;
	for (int r = 0; r < t; r++)
	{
		cin >> b >> w;
		cin >> x >> y >> z;
		if (x + z < y)			cout << x*b + (x+z)*w << endl;
		else
		{
			if (y + z < x)
				cout << y*w + (y+z)*b << endl;
			else
				cout << x*b + y*w << endl;
		}
	}
	return 0;
	
}