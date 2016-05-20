#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Cood
{
    public:
        double x;
        double y;
        double dist;
        Cood(double x, double y):x(x), y(y),dist(10000000){}
        Cood(){}
};
int main() 
{
    int n = 0;
    while(true)
    {
        cin >> n;
        if(n == -1)
            break;
        int nSize = (4 * n) + 2;
        Cood nodes[nSize];
        nodes[0] = Cood(0,5);
        nodes[nSize - 1] = Cood(10,5);
        pair< pair<double, double> , pair<double,double> >doors[3 * n];
        double map[nSize][nSize]; 
        int index = 1;
        double input[n][5];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cin >> input[i][j];
            }
        }
        for(int i = 0; i < n; i++)
        {
            double x = input[i][0];
            for(int j = 1; j < 5; j++)
            {
                double y = input[i][j];
                nodes[index] = Cood(x,y);
                index++;
            }
        }
        index = 0;
        for(int i = 0;i < n; i++)
        {
            double x = input[i][0];
            for(int j = 0; j < 5; j+=2)
            {
                if(j == 0)
                {
                    doors[index] = make_pair(make_pair(x,0),make_pair(x,input[i][j + 1])); 
                }
                if(j == 2)
                {
                    doors[index] = make_pair(make_pair(x,input[i][j]),
                    make_pair(x,input[i][j + 1])); 
                }
                if(j == 4)
                {
                    doors[index] = make_pair(make_pair(x,input[i][j]),
                    make_pair(x,10);
                    break;
                }
                index++;
            }
        }
        for(int i = 0;i < nSize; i++)
        {
            Cood curr = nodes[i];
            for(int j = 0; j < nSize; j++)
            {
                
            }
        }
    }
    return 0;
}
