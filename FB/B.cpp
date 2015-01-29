#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
long long s1, s2, s3, n;
bool finde;
struct stuff
{
	long long s1, s2, s3;
};
stuff a[30];

void dfs(int pos, int x1, int x2, int x3)
{
	if (pos >= n)
	{
		if ((x1 == s1) && (x2 == s2) && (x3 == s3))
			finde = true;
		return;
	}	
	dfs(pos+1, x1, x2, x3);
	dfs(pos+1, x1 + a[pos].s1, x2 + a[pos].s2, x3 + a[pos].s3);
}
int main()
{
	int t;
	cin >> t;
	for (int r = 0; r < t; r++)
	{
		cin >> s1 >> s2 >> s3;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
		finde = false;
		dfs(0,0,0,0);
		if (finde) cout << "Case #" << r+1 << ": " << "yes" << endl;
		else  cout << "Case #" << r+1 << ": " << "no" << endl;
	}
	return 0;
}