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
        bool ones = true;
        int n = 0;
        cin >> n;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int curr = 0;
            cin >> curr;
            if(curr != 1)
                ones = false;
            res ^= curr;
        }
        if(ones)
        {
            cout << ((res == 0)? "John" : "Brother") << endl;
        }
        else
        {
            cout << ((res == 0)? "Brother" : "John") << endl;
        }
    }
    return 0;
}

