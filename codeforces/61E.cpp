#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <assert.h>

using namespace std;

long long tree[2][1000001];
int n;
pair <long long, long long> a[1000001];
int b[1000001];

long long find(int ind, int t)
{
    if (ind == 0) return 0; 
    return (tree[t][ind] + find(ind - (ind & -ind), t));
}

void insert(int ind, long long num, int t)
{
    if (ind > 1000000) return;
    tree[t][ind] += num;
    insert(ind + (ind & -ind), num, t);
}

int main()
{
    int size = 0;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++)
    {
        if ((i == 0) || (a[i].first != a[i-1].first))
        {
            size++;
            b[a[i].second] = size;          
        }
    }
    long long res = 0;
    long long tmp;
    for (int i = n-1; i >= 0; i--)
    {
        insert(b[i], 1, 0);
        res += find(b[i]-1, 1);
        tmp = find(b[i]-1, 0);
        insert(b[i], tmp, 1);           
    }
    cout << res << endl;
    
}
