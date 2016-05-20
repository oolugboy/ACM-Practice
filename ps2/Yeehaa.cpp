#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int t = 0;
    cin >> t;
    int index = 0;
    while(index < t)
    {
        double R = 0;
        double n;
        cin >> R >> n;
        double r = (R * sin((3.141592653589793/n)))/(double)(1 + sin((3.141592653589793/n)));
        index++;
        cout << "Scenario " << "#" << index << ":" << endl;
        cout << setprecision(3) << fixed << r << endl;
        cout << endl;
    }
    return 0;
}

