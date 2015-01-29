#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <assert.h>

using namespace std;
long long n,k,countb,numer;
long long a[200002];
long long b[200002];
long long dpcount[200001];
const long long modulo = 1000000007 ;
vector <long long> luckset;

long long akapow(long long num, long long power)
{
    if (power == 1) return num;
    long long tmp;
    tmp = akapow(num, power/2);
    tmp = (tmp*tmp) % modulo;
    if (power % 2 == 0) return tmp;
    else                return ((tmp*num) % modulo);
}
long long comb(long long large, long long small)
{
    if (large < small) return 0;
    if (small < 0) return 0;
    long long numerator = numer;
    long long deno = 1;
    for (long long i = 1; i <= small; i++) deno = (deno * i) % modulo;
    for (long long i = 1; i <= large - small; i++) deno = (deno *i) % modulo;
    deno = akapow(deno, modulo - 2);
    return (numerator * deno) % modulo;
}
bool lucky(long long num)
{   
    stringstream ss;
    ss << num;
    string tmp = ss.str();
    for (long long i = 0; i < tmp.length(); i++)
        if ((tmp[i] != '4') && (tmp[i] != '7')) return false;
    return true;
}

void init()
{
    cin >> n >> k;
    for (long long i = 0; i < n; i++) 
    {
        cin >> a[i];
        if (lucky(a[i])) luckset.push_back(a[i]);
    }
    sort(luckset.begin(), luckset.begin()+luckset.size());
    long long runner;
    for (long long i = 0; i < luckset.size(); i++)
    {
        if (i == 0) 
        {
            countb = 1;     runner = 1;
        }
        else
        {
            if (luckset[i] != luckset[i-1])
            {
                b[countb-1] = runner;
                countb++;
                runner = 1;
            }
            else    runner++;
        }
    }
    b[countb-1] = runner;
}

void dpluck()
{
    dpcount[0] = 1;
    for (long long i = 0; i < countb; i++)
    {
        for (long long j = i+1; j >= 1; j--)
            dpcount[j] = (dpcount[j] + ((dpcount[j-1] * b[i]) % modulo)) % modulo;
    }
}

void solve()
{
    numer = 1;
    for (long long i = 1; i <= n-luckset.size(); i++) numer = (numer*i) % modulo;
    long long res = 0;
    for (long long i = 0; i <= countb; i++)
    {
        res = (res + (dpcount[i]*comb(n-luckset.size(), k-i))) % modulo;
    }
    cout << res << endl;
}

void diagnose()
{   
    int counter = 0;
    for (int i = 0; i < 1 << 25; i++)
        if (lucky(i)) counter++;
    cout << counter << endl;
}

int main()
{
//  diagnose();
    init();
    dpluck();
    solve();
}
