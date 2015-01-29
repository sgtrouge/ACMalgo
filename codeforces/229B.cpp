#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <set>
#include <assert.h>
using namespace std;

typedef pair<int,int> pp;
priority_queue< pp, vector<pp>, greater<pp> > minheap;
vector < pp > a[100001];
set < pp > b;
int d[100001];
int n,m;
int main()
{
    cin >> n >> m;
    for (int i = 2; i <= n; i++ ) d[i] = 1 << 30;
    for (int i = 0; i < m; i++)
    {   
        int u,v,g;
        cin >> u >> v >> g;
        a[u].push_back(make_pair(g,v));
        a[v].push_back(make_pair(g,u));
    }
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num ; j++)
        {
            int tmp;
            cin >> tmp;
            b.insert(pp(tmp,i));
        }
    }
    minheap.push(pp(0,1));
    while (minheap.size() > 0)
    {
        pair<int,int> tmp = minheap.top();
        minheap.pop();
        //cout << tmp.first << " " << tmp.second << endl;
        if (tmp.second == n) 
        {
            cout << tmp.first << endl;
            return 0;
        }
        if (b.find(tmp) != b.end())
        {
            tmp.first++;
            minheap.push(tmp);
            continue;
        }
        //cout << "TOP " << tmp.first << " " << tmp.second << endl;
        for (int i = 0; i < a[tmp.second].size(); i++)
        {   
            pp v = a[tmp.second][i];
            //cout << v.first << " " << v.second << endl;
            //cout << d[v.second] << "," << tmp.first + v.first << endl;
            if (d[v.second] > tmp.first + v.first)
            {
                d[v.second] = tmp.first + v.first;
                minheap.push(pp(d[v.second], v.second));
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
