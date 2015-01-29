#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>

using namespace std;
int a[1000001];
string modulo[7] = {"1869","1968","1689","6198","1698","1986","1896"};
int countt[10];
int main()
{
    string s,res;
    cin >> s;
    a[0]=1;
    for (int i =1; i <= 1000000; i++) a[i] = (a[i-1]*10) %7;
    for (int i =0; i < s.length();i++) countt[s[i]-48]++;
    countt[9]--; countt[8]--; countt[6]--; countt[1]--;
    int l;
    for (int i = 0; i <= 9; i++) if (countt[i] > 0) l = i;
    int modu = 0;
    if (l == 0)
    {
        cout << 1869;
        for (int i = 0; i < countt[0]; i++) cout << 0;
        cout << endl;
        return 0;
    }
    int mu = s.length()-1;
    for (int k = 9; k>= 0; k--)
    {
        for (int j = 1; j <= countt[k]; j++)
        {
            modu = (modu + k * a[mu]) % 7;
            cout << char(k+48);
            mu--;
        }
    }
    cout << res + modulo[(7-modu)%7];    
    return 0;
}
