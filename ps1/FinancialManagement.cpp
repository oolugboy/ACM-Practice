#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    float tot = 0;
    float am = 12;
    float current = 0;
    for(int i = 0; i < 12; i++)
    {
        cin >> current; 
        tot += current;
    }
    cout << "$" << (float)(tot/am) << endl;
    return 0;
}
