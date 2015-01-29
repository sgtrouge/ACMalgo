#include <iostream>
#include <cstdio>

using namespace std;

int solve()
{
    int x;
    cin >> x;
    if (x == 1) return 1;
    if (x == 2) return 3;
    if (x == 3) return 5;
    for (int k = 1; k < x; k++)
    {
        if ((k*k + (k-1)*(k-1) < x) && (x <= k*k + (k+1)*(k+1)))    
            return 2*k+1;
    }
    return 0;
}

int main()
{
    cout << solve() << endl;
}
