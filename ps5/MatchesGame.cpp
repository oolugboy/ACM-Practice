#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int test = 0;
    while(cin >> test)
    {
        int vals[test];        
        for(int i = 0; i < test; i++)
        {
            cin >> vals[i];
        }
        int res = 0;
        for(int i = 0;i < test; i++)
        {
            res ^= vals[i];   
        }
        cout << ((res == 0)? "No" : "Yes") << endl; 
    }
    return 0;
}
