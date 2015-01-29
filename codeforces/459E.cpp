#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <assert.h>

struct edge
{
    int u, v;
    int g;
};

bool lessweight(edge a, edge b)
{
    return a.g < b.g;
}
using namespace std;
edge eg[300002];
vector <edge> temp;
int dp[300002];
int n,m;
int main()
{
    cin >> n >> m;
    int res = 0;
    for (int i = 0; i < m; i++) cin >> eg[i].u >> eg[i].v >> eg[i].g;
    sort(eg, eg+m, lessweight);
    for (int i = 0; i < m; i++)
    {
        if ((i == 0) || (eg[i].g != eg[i-1].g))
        {
            for (int j = 0; j < temp.size(); j++)       dp[temp[j].u] = max(dp[temp[j].u],temp[j].v);
            temp.clear();
        }
        if (dp[eg[i].u] + 1 > dp[eg[i].v])
        {
            edge tmp;    tmp.u = eg[i].v; tmp.v = dp[eg[i].u]+1;
            temp.push_back(tmp);
        }
    }
    for (int j = 0; j < temp.size(); j++)   dp[temp[j].u] = temp[j].v;
    temp.clear();
    for (int i = 1; i <= n; i++) res = max(res, dp[i]);
    cout << res << endl;
} 
