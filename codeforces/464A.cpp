#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <assert.h>
#include <string>
using namespace std;
int n,p;
int n1  = 99;
int n2 = 99;
int last;
int dp[1005][26][26];
string s;
void solve()
{
    cin >> n >> p;
    cin >> s;
    for (int run = n-1; run >= 0; run--)
        {
            for (int i = s[run]-97+1; i < p; i++)
            {
                if (run > 0)  if (s[run-1] - 97 == i) continue;
                if (run > 1)  if (s[run-2] - 97 == i) continue;
                for (int j = 0; j < p; j++)
                {
                    if (run > 0) if (s[run-1] - 97 == j) continue;
                    if (run+1 <= n-1) if (i == j) continue;
                    for (int k = 0; k < p; k++)
                    {
                        if (run+2 <= n-1) if (i == k) continue;
                        if (dp[run+1][j][k] >= 0)
                        { 
                            last = run;
                            n1 = i;
                            n2 = j;
                            dp[run][i][j] = k;
                            return;
                        }   
                    }
                }
            }
            for (int i = 0; i < p; i++)
            {
                for (int j = 0; j < p; j++)
                {
                    dp[run][i][j] = -1;
                    if (i == j) continue;
                    for (int k = 0; k < p; k++)
                    {
                        if (i == k) continue;
                        if (dp[run+1][j][k] >= 0) 
                        {
                            dp[run][i][j] = k;
                            break;
                        }
                    }
                }
            } 
        }       
}

int main()
{
    solve();
    if (n1 == 99)
    {
        cout << "NO" << endl;
        return 0;
    }   
    for (int i = 0; i < last; i++) cout << s[i];
    for (int i = last; i < n; i++)
    {
        cout << char(n1+97);
        int tmp = dp[i][n1][n2];
        n1 = n2;        n2 = tmp;
    }
    cout << endl;
}
