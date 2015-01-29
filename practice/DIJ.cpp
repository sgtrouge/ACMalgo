#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
vector < pair<int, long long> > adj[100005];
struct t
{
    long long g;
    int u;
    int v;
};
struct comp
{
    bool operator()(t& t1, t& t2)
    {
        return t1.g > t2.g;
    }
};
priority_queue <t, vector<t>, comp > heap;
int trace[100005];
int pass[100005];
int n,m;

void dijkstra()
{
    t init; init.g = 0; init.u = 1; init.v = 0;
    heap.push(init);
    while (heap.size() != 0)
    {
        t top = heap.top();
        heap.pop();
        int g = top.g;
        int u = top.u;
        if (pass[u] == 1) continue;
        pass[u] = 1;
        trace[u] = top.v;
        if (u == n) break;
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j].first;
            t tmp;
            tmp.g = g+adj[u][j].second;
            tmp.u = v;
            tmp.v = u;
            heap.push(tmp);
        }
    }
}

void find(int u)
{
    if (u == 0) return;
    find(trace[u]);
    cout << u << " ";
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {   
        int u, v;    long long g;
        cin >> u >> v >> g;
        adj[u].push_back(make_pair(v,g));
        adj[v].push_back(make_pair(u,g));
    }
    dijkstra();
    if (trace[n] == 0) 
    {
        cout << -1 << endl;
        return 0;
    }
    find(n);
    cout << endl;
}