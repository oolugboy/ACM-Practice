#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dist(int a,int b)
{
    return abs(a - b);
}
int main() 
{
    int v = 0, p = 0;
    cin >> v >> p;
    int vils[v];
    int cost[v][v];
    int dp[v][p + 1];
    for(int i = 0; i < v; i++)
    {
        cin >> vils[i];
    }
   /* for(int i = 0; i < v; i++)
    {
        cerr << " The vils " << vils[i] << endl;
    } */
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cost[i][j] = 0;
        }
        for(int j = 0; j < p + 1; j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < v; i++)
    {
        for(int j = i + 1; j < v; j++)
        {
            for(int k = i + 1; k < j; k++)
            {
                cost[i][j] += min(dist(vils[i], vils[k]),dist(vils[j],
                vils[k]));
            }
        }
    }
   /* for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < (p + 1); j++)
        {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    } */
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i][1] += dist(vils[i], vils[j]);
        }
    }
  /*  for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < (p + 1); j++)
        {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    } */

    for(int i = 1; i < v; i++)
    {
        for(int j = 2; j < p + 1; j++)
        {
            dp[i][j] = dp[i - 1][j - 1];
            for(int k = 1; k < i - 2; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + cost[k][i]);
            }
        }
    }
 /*   cerr << " **** after dp *** " << endl;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < (p + 1); j++)
        {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }  */
    int res = dp[v - 1][p];
    for(int i = 0; i < v; i++)
    {
        int test = dp[i][p];
        for(int j = i + 1; j < v; j++)
        {
            test += dist(vils[i], vils[j]);
        }
        res = min(res,test);
    }
    cout << res << endl;
    return 0;
}
