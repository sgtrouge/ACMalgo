#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
#define maxN 100001
int n;
int a[100001];
int dp[100001];
int prime[100001];
bool isprime[100001];
vector <int> primelist;
void eras()
{
    primelist.clear();
    for (int i = 0; i < maxN; i++) isprime[i] = true;   isprime[1] = false;
    for (int i = 2; i < sqrt(maxN); i++) 
    {
        if (isprime[i] == false) continue;
        int j = 2;
        while (i * j <= maxN)
        {
            isprime[i*j] = false;
            j++;
        }
        primelist.push_back(i);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)     cin >> a[i];
    eras();
    int tmp[100001];
    for (int i = 0; i < n; i++)
    {
        int tmpmax = 0;
        tmp[0] = 0;
        for (int j = 0; j < primelist.size(); j++)
        {
            if (primelist[j] > sqrt(a[i])) break;
            if (a[i] % primelist[j] == 0)
            {
                tmp[0]++;
                tmp[tmp[0]] = primelist[j];
                tmpmax = max(tmpmax, dp[primelist[j]]);
                while (a[i] % primelist[j] == 0) 
                        a[i] = a[i] / primelist[j]; 
            }
        }
        if (isprime[a[i]]) 
        {
            tmp[0]++;
            tmp[tmp[0]] = a[i];
            tmpmax = max(tmpmax, dp[a[i]]);
        }
        for (int i = 1; i <= tmp[0]; i++)   dp[tmp[i]] = tmpmax+1;
        //for (int i = 0; i < 10; i++) cout << dp[i] << " ";
        //cout << endl; 
    }
    int res = 1;
    for (int i = 0; i < maxN; i++) res = max(res, dp[i]);
    cout << res << endl;
}
