#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <assert.h>

using namespace std;
long long a[100001];

struct trienode
{
    vector <int> nextnode;
    vector <int> nextpos;
    long long mindp;
};

vector <trienode> trietree;
int n;

void pushnode(long long num)
{
    trienode tmp;
    tmp.mindp = num;
    trietree.push_back(tmp);
}

int check( trienode tmp, int bit)
{
    for (int i = 0; i < tmp.nextnode.size(); i++)
    if (tmp.nextnode[i] == bit) return i;
    return -1;
}
int main()
{
    cin >> n;
    long long total = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        total = total ^ a[i];
    }
    pushnode(0);
    long long res = total;
    long long tmp = 0;
    long long inv;
    for (int i = n-1; i > 0; i--) 
    {
        tmp = tmp ^ a[i];
        res = max(res, tmp);
        res = max(res, total ^ tmp);
        int pos = 0;
        for (int j = 40; j >= 0; j--)
        {
            int bitj = (tmp >> j) & 1;
            if (bitj == 0) continue;
            int find = check(trietree[pos], j);
            if (find != -1)
            {
                 trietree[pos].mindp = min(trietree[pos].mindp, tmp);
                 pos = trietree[pos].nextpos[find];
            }
            else
            {
                pushnode(tmp);
                trietree[pos].nextpos.push_back(trietree.size()-1);
                trietree[pos].nextnode.push_back(j);
                pos = trietree.size()-1;
            }
        }
        inv = 1; inv = (inv << 42) - 1; inv = inv ^ (total ^ tmp);   
    
        pos = 0;    
                
        for (int j = 40; j >= 0; j--)
        {
            if (((inv >> j) & 1) == 0) continue;
            
            if (check(trietree[0], j))
            {
                for (int k = j; k >= 0; k--)
                {
                    //if (((inv >> k) & 1) == 0) continue;
                    int find = check(trietree[pos], k);
                    if ((((inv >> k) & 1) == 1) && (find != -1))
                    {
                        pos = trietree[pos].nextpos[find];
                        res = max(res, trietree[pos].mindp ^ (total ^ tmp));
                        continue;
                    }
                }
                break;
            }
        }
    }   
    cout << res << endl;
}
