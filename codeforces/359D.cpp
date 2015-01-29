#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <set>
#include <assert.h>
using namespace std;

vector <int> res;
int a[300010];
int spgcd[300010][20];
int spmin[300010][20];
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int findgcd(int l, int r)
{
    int tmp = a[l];
    for (int i = 20; i >= 0; i--)
    {
        if (l + (1 << i) - 1 <= r)
        {
            tmp = gcd(tmp, spgcd[l][i]);
            l = l + (1 << i);
        }
    }   
    return tmp;
}

int findmin(int l, int r)
{
    int tmp = a[l];
    for (int i = 20; i >= 0; i--)
    {
        if (l + (1 << i) - 1 <= r)
        {
            tmp = min(tmp, spmin[l][i]);
            l = l + (1 << i);
        }
    }   
    return tmp;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
         cin >> a[i];
         spmin[i][0] = a[i];
         spgcd[i][0] = a[i];
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j + (1 << i) - 1 >= n) break;
            spgcd[j][i] = gcd(spgcd[j][i-1], spgcd[j + (1 << (i-1))][i-1]);
            spmin[j][i] = min(spmin[j][i-1], spmin[j + (1 << (i-1))][i-1]);
        }
    }
    int max = 0;        int l = 0;      int r = n-1; 
    while (l <= r)
    {
        int mid = (l+r)/2;      
        bool checked = false;
        for (int i = 0; i < n; i++)
        {
            if (i + mid >= n) break;
            int tmpgcd = findgcd(i, i + mid);
            int tmpmin = findmin(i, i + mid);
            if (tmpgcd == tmpmin)
            {
                checked = true;
                break;
            }   
        }
        if (checked)
        {
            max = mid;
            l = mid + 1;
        }
        else    r = mid - 1;
    }
    res.clear();
    for (int i = 0; i < n; i++)
    {   
        if (i + max >= n) break;
        int tmpgcd = findgcd(i, i + max);
        int tmpmin = findmin(i, i + max);
        if (tmpgcd == tmpmin) res.push_back(i+1);       
    }
    cout << res.size() << " " << max << endl;
    for (int i = 0; i < res.size(); i++)    cout << res[i] << " ";
    cout << endl;
    return 0;
}
