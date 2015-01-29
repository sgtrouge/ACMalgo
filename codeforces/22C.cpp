#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
using namespace std;
typedef pair<int, int> ii;

ii a[200000];
int main()
{
    int n;

    vector <int> reslist;
    cin >> n;

    for (int i = 0; i< n; i++) 
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second)
        {
            int tmp = a[i].first;
            a[i].first = a[i].second;
            a[i].second = tmp;
        }
    }
    sort(a, a+n);
    int r = a[0].second;        
    reslist.push_back(r);
    for (int i = 1; i < n; i++)
    {
        if ((a[i].first <=r ) && (a[i].second >= r)) continue;
        else
        {
            if (a[i].second < r)    
            {
                r = a[i].second;
                reslist[reslist.size()-1] = r;
            }
            else
            {
                r = a[i].second;
                reslist.push_back(r);
            }
        }
    }
    cout << reslist.size() << endl;
    for (int i = 0; i < reslist.size(); i++) cout << reslist[i] << " ";
    cout << endl;
}
