#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int counter[1000005];
vector <int> ll[1000005];

bool check[1000005];
struct comp
{
bool operator()(int &a, int &b)
{
	return (a > b);
}
};
priority_queue <int, vector<int>, comp> q;

int main()
{
	int n;
	int maxbound = 0;
	cin >> n;
	for (int i = 1; i < 1000001;i++) 		check[i] = false;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		int last = 0;
		for (int i = 0; i < k; i++)
		{
			int tmp;
			cin >> tmp;
			check[tmp] = true;
			if (last != 0)	
			{
					counter[tmp]++;
					ll[last].push_back(tmp);
			}
			last = tmp;
			maxbound = max(maxbound, tmp);
		}
	}
	for (int i = 1; i <= maxbound; i++)
	{
		if ((counter[i] == 0) && (check[i])) q.push(i);
	}
	while (q.size() > 0)
	{
		int tmp = q.top();
		q.pop();
		cout << tmp << " ";
		for (int i = 0; i < ll[tmp].size(); i++)
		{
			counter[ll[tmp][i]]--;
			if (counter[ll[tmp][i]] == 0)
			{
				q.push(ll[tmp][i]);
			}
		}
	}
	cout << endl;
	return 0;
}