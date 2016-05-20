#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool sumExists(int diff)
{
    int c = (2 * diff) * -1;
    float res = -1 + (sqrtf(1 - (4*c)));
    res = res / (float)2;
    int resInt = res;
   // cout << (float)resInt << " and float " << res << endl;
    if((float)resInt == res)
    {
       // cout << " accepted " << (float)resInt << " and float " << res << endl;
        return true;
    }
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0;
    cin >> n;
    int count = 0;
    for(int i = 1; i < (n + 1); i++)
    {
        int test = (i * (i + 1))/2;
        int diff = test - n;
        if(diff >= 0)
        {
            if(sumExists(diff))
            {
              //  cerr << " the test " << i << endl;
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
