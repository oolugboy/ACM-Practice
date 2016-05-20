#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    short size = 0;
    cin >> size;
    short init[size][size];
    for(short i = 0; i < size; i++)
    {
        for(short j = 0; j < size; j++)
        {
            cin >> init[i][j];
        }
    }
    short dp[size][size];
    int vertTot = 0;
    int hozTot = 0;
    int intercept = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            dp[i][j] = init[i][j];
            vertTot = 0;
            hozTot = 0;
            intercept = 0;
            if(i > 0)
            {
                hozTot = dp[i - 1][j];
            }
            if(j > 0)
            {
                vertTot = dp[i][j - 1];
            }
            if(i > 0 && j > 0)
            {
                intercept = dp[i - 1][j - 1]; 
            }
            dp[i][j] += ((vertTot + hozTot) - intercept);
        }
    }
    vector< pair<short, short> > vPoints;
    vector<pair<short, short> > hPoints;
    short rMax = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            short lMax = 0;
            lMax = dp[i][j];
            for(int k = i - 1; k >= 0; k--)
            {
                vPoints.push_back(make_pair(k,j));  
                short test = dp[i][j] - dp[k][j];
                if(i == 3 && j == 1)
                {
                }
                if(test > lMax)
                {
                    lMax = test;
                }
            }
            for(int k = j - 1; k >= 0; k--)
            {
                hPoints.push_back(make_pair(i,k));
                short test = dp[i][j] - dp[i][k];
                if(test > lMax)
                {
                    lMax = test;
                }
            }
            int vSize = vPoints.size();
            int hSize = hPoints.size();
            pair<short, short> rc1,rc2;
            int maxTest = 0;
            for(int k = 0; k < vSize; k++)
            {
                pair<short,short> c1 = vPoints[k];
                for(int l = 0; l < hSize; l++)
                {
                    pair<short, short>c2 = hPoints[l];
                    short test = (dp[i][j] - ((dp[c1.first][c1.second] +
                    dp[c2.first][c2.second]) - dp[c1.first][c2.second]));
                    if(i == 3 && j == 1)
                    {
                    }
                    if(test > lMax)
                    {
                        lMax = test;
                    }
                    if(i == 3 && j == 1)
                    {
                        if(test > maxTest)
                        {
                            rc1 = c1;
                            rc2 = c2;
                            maxTest = test;
                        }
                    }
                }
            }
            vPoints.clear();
            hPoints.clear();
            if(lMax > rMax)
            {
                rMax = lMax;
            }
        }
    }
    cout << rMax << endl;
    return 0;
}

