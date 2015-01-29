#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <istream>
using namespace std;
bool comp(const int&a, const int &b)
{
	return a < b;
}
string tmp()
{
	string res;
	return res;
}
vector <int> a;
int main()
{
	int z1 = 2;
	int z2 = 3;
	string tmp;
	while (getline(cin,tmp))
	{
		stringstream st;
		st << tmp;
		st >> z1 >> z2;
		cout << z1 << " " << z2 << endl;
	}
}