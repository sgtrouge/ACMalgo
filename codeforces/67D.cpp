#include <iostream>
#include <cstdio>
#include <math.h>
const long long maxint = 1000000001;
using namespace std;
int dp[1000001];
int top[1000001];
int bot[1000001];
int res = 0;
int main()
{
        int n;
        int tmp;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> top[i];
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            bot[tmp] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int* pos = lower_bound(dp, dp+n, -bot[top[i]]);
            res = max(res, int(pos-dp));
            dp[pos-dp] = -bot[top[i]];
        }
        cout << res+1 << endl;
        
}
