#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <assert.h>

using namespace std;

int n;
long long a[100002];
long long dp[100002];
void init()
{
    cin >> n;
    int b;
    for (int i = 0; i < n; i++) 
    {
        cin >> b;
        a[b]++;
    }
}

void solve()
{
    dp[1] = a[1];
    for (long long i = 2; i <= 100000; i++)
        dp[i] = max(dp[i-2] + i*a[i], dp[i-1]);
    cout << dp[100000] << endl;
}
int main()
{
    init();
    solve();
}
