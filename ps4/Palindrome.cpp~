#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string rev(string a)
{
    string res = "";
    int size = a.size();
    for(int i = 0; i < size; i++)
    {
        res = a[i] + res;
    }
    return res;
}


int main() {
    int size = 0;
    cin >> size;
    string val  = "";
    cin >> val;
    val = "x" + val;
    string r = rev(val);
    r = "y" + r;
    unsigned short ** dp = new unsigned short *[(size + 1)];
    for(int i = 0; i < (size + 1); i++)
    {
        dp[i] = new unsigned short[(size + 1)];
    }
    for(int i = 0; i < size + 1; i++)
        for(int j = 0; j < size; j++)
            dp[i][j] = 0;

    for(int i = 1; i < size + 1; i++)
    {
        for(int j = 1; j < size + 1; j++)
        {
            if((int)r[i] == (int)val[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; 
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << size - dp[size][size] << endl;
    return 0;
}
