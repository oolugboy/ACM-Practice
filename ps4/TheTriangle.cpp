#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int r = 0;
    cin >> r;
    int vals[r][r];
    int res[r][r];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            vals[i][j] = 0;
            res[i][j] = 0;
        }
    }
    int off = 1;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < off; j++)
        {
            cin >> vals[i][j];
        }
        off++;
    }
    off = 2;
    res[0][0] = vals[0][0];
    for(int i = 1; i < r; i++)
    {
        for(int j = 0; j < off; j++)
        {
            int l = 0;
            int r = 0;
            if(i > 0)
            {
                r = res[i - 1][j];

                if(j > 0)
                {
                    l  = res[i - 1][j - 1];
                }
                res[i][j] = max((r + vals[i][j]), (l + vals[i][j]));
            }
        }
        off++;
    }
    int maxPath = 0;
    int i = r - 1;
    for(int j = 0; j < r; j++)
    {
        maxPath = max(maxPath, res[i][j]);
    }
    cout << maxPath << endl;
    return 0;
}

