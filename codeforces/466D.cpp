#include <iostream>
#include <cstdio>
#include <math.h>
#include <assert.h>

long long a[2001];
long long dp[2001][2001];
int n, h;
const long long module = 1000000007;
long long total = 0;
using namespace std;
int main()
{
    cin >> n >> h;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[0] == h-1) dp[0][1] = 1;
    if ((a[0] == h) || (a[0] == h-1)) dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (h-a[i] >= 0)
        {
            dp[i][h-a[i]] = dp[i-1][h-a[i]];    
            if (h-a[i] - 1 >= 0) 
            {
                dp[i][h-a[i]] = (dp[i][h-a[i]] + dp[i-1][h-a[i]-1]) % module;
                dp[i][h-a[i]-1] = (dp[i][h-a[i]]* (h-a[i])) % module;
            }
        }
    }
    cout << dp[n-1][0] << endl;
}
