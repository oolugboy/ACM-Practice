#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        long int val = 0;
        cin >> val;
        int exp = 0;
        int best = 0;
        while(exp < 31)
        {
            if((val % (int) pow(2,exp)) != 0)
            {
                best = exp - 1;
                break;
            }
            exp++;
        }
        long int low = val - (pow(2,best) - 1);
        long int high = val + (pow(2,best) - 1);
        cout << low << " " << high << endl;
    }
    return 0;
}
