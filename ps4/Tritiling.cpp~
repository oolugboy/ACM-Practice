#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n = 0;
    while(true)
    {
        cin >> n;
        if(n == -1)
        {
            break;
        }
        int d[(n + 1)];
        int a[(n + 1)];
        for(int i = 0; i < (n +1); i++)
        {
            d[i] = 0;
            a[i] = 0;
        }
        d[0] = 1;
        a[1] = 1;
        for(int i = 2; i < (n + 1); i++)
        {
            if(i % 2 == 0)
            {
                d[i] = (2 * a[i - 1]) + d[i - 2]; 
            }
            else
            {
                a[i] = d[i - 1] + a[i - 2];
            }
        }
        cout << d[n] << endl;
    }
    return 0;
}
