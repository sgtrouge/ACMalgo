#include <iostream>
using namespace std;
int main()
{
	long long n;
	long long res = n;
	cin >> n;
	sign = -1;
	for (int i = 5; i <= n; i*5)
	{
		long long tmp = n / i;
		res = res + sign*(tmp/2)*i;
		sign = sign*-1;
	}
}
