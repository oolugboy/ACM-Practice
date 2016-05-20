#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t = 0;
    cin >> t;
    while(t--)
    {
        int val = 0;
        cin >> val;
        int res = 0;
        int special = 5;
        while(special <= val)
        {
            res += (val/special);
            special *= 5;
        }
        cout << res << endl;
    }
    return 0;
}

