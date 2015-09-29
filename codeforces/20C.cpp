#include <iostream>
#include "math.h"
#include <utility>
#include <queue>
#include "assert.h"
using namespace std;

typedef pair<int, pair<int,int> > pp;
int n,m;
vector<pair<int, int> > adj[100001];  
// first = value, second.first = node cur, second.second = node last
int trace[100001];

struct comp {
    bool operator()(pp &a, pp &b) {
        return a.first > b.first;
    }
};

priority_queue<pp, vector<pp>, comp > q;

void dij() {
    pp init;                init.first = 0;     
    init.second.first = 1;  init.second.second = 1;
    q.push(init);
    while (q.size() > 0) {
        pp top = q.top();
        q.pop();
        if (trace[top.second.first]) continue;
        trace[top.second.first] = top.second.second;
        if (top.second.first == n) break;
        for (int i = 0; i < adj[top.second.first].size(); i++) {
            int tmp = top.first + adj[top.second.first][i].first;
            q.push(
                make_pair(tmp, 
                          make_pair(
                            adj[top.second.first][i].second, 
                            top.second.first
                          )
                )
            );
        }
    }
}
void recur(int t) {
    if (t == 1) {
        cout << 1 << " ";
        return;
    }
    recur(trace[t]);
    cout << t << " ";
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, g;
        cin >> u >> v >> g;
        adj[u].push_back(make_pair(g,v));
        adj[v].push_back(make_pair(g,u));
    }
    dij();
    if (trace[n] == 0) cout << -1;
    else               recur(n);
    cout << endl;
    return 0;
}