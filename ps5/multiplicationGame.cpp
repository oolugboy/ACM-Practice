#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    double n = 0;
    while(cin >> n)
    {
        while(n > 18)
        {
            n /= 18;
        }
        cout << ((n > 9)? "Ollie wins." : "Stan wins.") << endl; 
    }
}
