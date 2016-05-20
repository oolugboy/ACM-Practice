#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    while(true)
    {
        float curr = 0;
        cin >> curr;
        if(curr == (float)0)
        {
            break;
        }
        float tot = 0;
        int am = 0;
        float div = 2;
        while(tot < curr)
        {
            tot += ((float)1/div);
            div++;
            am++;
        }
        cout << am << " card(s) " <<  endl;
    }
    return 0;
}
