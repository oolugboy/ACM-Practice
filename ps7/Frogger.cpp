#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Cood
{
    public:
        int x;
        int y;
        Cood(int x, int y):x(x), y(y){}
        Cood(){}
};
double getDist(Cood a, Cood b)
{
    return double(sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2)));
}
int main() 
{
    int n = 0;
    int index = 0;
    while(true)
    {
        cin >> n;
        if(n == 0)
            break;
        Cood points[n];
        for(int i = 0; i < n; i++)
        {
            int x = 0, y = 0;
            cin >> x >> y;
            points[i] = Cood(x,y);
        }
        double dists[n][n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                dists[i][j] = getDist(points[i], points[j]);
        }
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dists[i][j] = min(dists[i][j], max(dists[i][k],
                    dists[k][j]));
                }
            }
        }
        index++;
        cout << "Scenario #" << index << endl;
        cout << "Frog Distance = " << setprecision(3) << fixed <<
        dists[0][1] << endl;
        cout << endl;
    }
    return 0;
}
