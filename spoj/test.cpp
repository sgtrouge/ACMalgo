#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

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
	int zz = 2;
	int zs = 3;
	stringstream tmp;
	tmp << "ZSDS JSKLDJS KLJ DSDS";
	string tmpz;
	string gets;
	while (tmp >> gets)
	{
		tmpz = tmpz + gets;
	} 
	cout << tmpz << endl;
	for (int i = 0; i < 100; i++) a.push_back(100-i);
}