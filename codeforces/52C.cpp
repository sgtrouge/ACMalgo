#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <assert.h>
#include <sstream>
#include <string> 
const long long bign = 1000000000000;
using namespace std;

int n;
int a[200001];
struct seg
{
    int l;
    int r;
    int mindp;
} tree[5000000];

long long up[5000000];
void init(int k, int l, int r)
{
    if (l > r) return;
    if (l == r)
    {
        tree[k].mindp = a[l];
        return;
    }
    int mid = (l+r)/2;
    init(k*2, l, mid);
    init(k*2+1, mid+1,r); 
    tree[k].mindp = min(tree[2*k].mindp, tree[2*k+1].mindp);    
}

long long find(int k, int l, int r, int d1, int d2, long long rem)
{
    if (l > r) return bign;
    if ((d2 < l) || (d1 > r)) return bign;
    if ((l >= d1) && (r <= d2))     
    {
        //cout << endl << " REM IS : " << rem << endl;
        //cout << " MIN SEG " << l << " - " << r << " is " << tree[k].mindp << endl;
        return tree[k].mindp + rem;
    }
    int mid = (l+r)/2;
    rem += up[k];
    return min(find(k*2, l, mid, d1, d2, rem), find(k*2+1, mid+1, r, d1, d2, rem)); 
}

void update(int k, int l, int r, int d1, int d2, long long add)
{
    if (l > r) return;
    if ((d2 < l) || (d1 > r)) return;
    if ((l >= d1) && (r <= d2)) 
    {
        //cout << " UP SEG " << l << " - " << r  << " with " << add << endl;
        up[k] += add;
        tree[k].mindp += add;
        return;
    }
    int mid = (l+r)/2;
    update(2*k, l, mid, d1, d2, add);
    update(2*k+1, mid+1, r, d1, d2 ,add);   
    tree[k].mindp = min(tree[2*k].mindp, tree[2*k+1].mindp) + up[k];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    init(1, 0, n-1);
    int com;
    cin >> com;
    string line;
    getline(cin, line);
    long long n1, n2, n3;
    while (true)
    {
        getline(cin, line);
        n3 = -1000001;
        stringstream ss(line);
        ss >> n1 >> n2 >> n3;
        if (n3 == -1000001)
        {
            if (n1 <= n2)
            {
                long long res = find(1, 0, n-1, n1, n2, 0);
                cout << res << endl;
            }
            else
            {
                long long res = find(1, 0, n-1, n1, n-1, 0);
                res = min(res, find(1, 0, n-1, 0, n2, 0));
                cout << res << endl;
            }
        }
        else
        {
            if (n1 <= n2)
                update(1, 0, n-1, n1, n2, n3);
            else
            {
                update(1, 0, n-1, n1, n-1, n3);
                update(1, 0, n-1, 0, n2, n3);
            } 
        }
        com--;
        if (com == 0) return 0;
    }
}
