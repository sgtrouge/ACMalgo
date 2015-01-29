#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
#include <assert.h>
using namespace std;
long long reseven, resodd;
int stickodd2, stickeven2;
int stickodd1, stickeven1;
int unstickodd2, unstickeven2;
int unstickodd1, unstickeven1;
int main()
{
    string a;
    cin >> a;
    int count = 0;
unstickeven1 = 0;       unstickeven2 = 1;

    for (int i = 0; i < a.length(); i++)
    {
        if (i == 0) count = 1;
        else            if (a[i] != a[i-1]) count++;
        if (count % 2 == 0) // even sep
        {
            if ((i+1) % 2 == 0) // even pos
            {
                reseven = reseven + stickeven2 + unstickodd2;
                resodd = resodd + stickeven1 + unstickodd1;
            }
            else                //  odd pos
            {
                reseven = reseven + unstickodd1 + stickeven1;
                resodd = resodd + stickeven2 + unstickodd2;
            } 
            if (i < a.length() - 1)
            {
                if ((i + 1) % 2 == 0)
                {
                    if (a[i] == a[i+1])     stickeven2++;
                    else                    unstickeven2++;         
                }
                else
                {
                    if (a[i] == a[i+1])     stickeven1++;
                    else                    unstickeven1++; 
                }
            }
        
        }
        else        // odd sep
        {

            if ((i+1) % 2 == 0) // even pos
            {
                reseven = reseven + unstickeven2 + stickodd2;
                resodd = resodd + unstickeven1 + stickodd1;
            }
            else                // odd pos 
            {
                reseven = reseven + stickodd1 + unstickeven1;
                resodd = resodd + stickodd2 + unstickeven2;
            } 
            if (i < a.length() - 1)
            {
                if ((i + 1) % 2 == 0)
                {
                    if (a[i] == a[i+1])     stickodd2++;
                    else                    unstickodd2++;          
                }
                else
                {
                    if (a[i] == a[i+1])     stickodd1++;
                    else                    unstickodd1++;  
                }
            }
        }
    }
    cout << reseven << " " << resodd << endl;
}
