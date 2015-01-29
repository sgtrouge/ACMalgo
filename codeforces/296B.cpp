#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <assert.h>

const long long modulo = 1000000007;
using namespace std;
int n;
string w,s;
long long dps1, dps2, tot, eq;
int main()
{
    dps1 = dps2 = 1;
    tot = eq = 1;
    cin >> n;
    cin >> w;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if ((w[i] == '?') && (s[i] == '?'))
        {
            dps1 = (dps1 * 55) % modulo;
            dps2 = (dps2 * 55) % modulo;
            eq = (eq * 10) % modulo;
            tot = (tot * 100) % modulo;
        }
        if ((w[i] != '?') && (s[i] != '?'))
        {
            if (w[i] < s[i]) dps2 = 0;
            if (w[i] > s[i]) dps1 = 0;
            if (w[i] != s[i]) eq = 0;
        }
        if ((w[i] != '?') && (s[i] == '?'))
        {
            dps1 = (dps1 * (('9' - w[i]) + 1)) % modulo;
            dps2 = (dps2 * (w[i] - '0' + 1)) % modulo;
            tot = (tot * 10) % modulo;
        }
        if ((w[i] == '?') && (s[i] != '?'))
        {
            dps2 = (dps2 * (('9' - s[i]) + 1)) % modulo;
            dps1 = (dps1 * (s[i] - '0' + 1)) % modulo;
            tot = (tot * 10) % modulo;
        }
    }
    tot = ((tot + 2*modulo) - dps1 - dps2 + eq) % modulo;
    cout << tot << endl;
}
