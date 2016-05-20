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
        string in = "";
        cin >> in;
        if((int)in[0] == 48)
        {
            break;
        }
        int size = in.size();
        long vals[size];
        long res[size];
        for(int i = 0; i < size; i++)
        {
            char * endPtr;
            char curr[1];
            curr[0] = in[i]; 
            vals[i] = strtol((curr),&endPtr,10);
            res[i] = 0;
        }
        long curr = 0;
        res[0] = 1;
        for(int i = 1; i < size; i++)
        {
            int test = (vals[i - 1] * 10) + vals[i];
            if(vals[i] != 0)
            {
                res[i] = res[i - 1];
            }
            if(test >= 10 && test <= 26)
            {
                if(i == 1)
                {
                    res[i] += 1;
                }
                else
                {
                    res[i] += res[i - 2];
                }
            }
        }
        cout << res[(size - 1)] << endl;
    }
    return 0;
}
