#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Node
{
    public:
        int id;
        int dist;
        bool visited;
        Node(int id):id(id), dist(1000000),visited(false){}
        Node(){}
};
int main() 
{
    int n = 0;
    while(cin >> n)
    {
        int d[n][n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> d[i][j];
            }
        }
        Node v[n];
        for(int i = 0; i < n; i++)
        {
            v[i] = Node(i); 
        }
        v[0].dist = 0;
        long tot = 0;
        for(int i = 0; i < n; i++)
        {
            int currVal = 10000000;
            int currInd = 0;

            for(int i = 0; i < n; i++)
            {
                if(v[i].visited == false)
                {
                    if(v[i].dist < currVal)
                    {
                        currVal = v[i].dist;
                        currInd = i;
                    }
                }
            }
            //cerr << " The currInd " << currInd << endl;
            v[currInd].visited = true;
            // cerr << " addind dist " << v[currInd].dist << endl;
            tot += v[currInd].dist;
            for(int j = 0; j < n; j++)
            {
                if(v[j].visited == false)
                {
                    if(d[currInd][j] < v[j].dist)
                    {
                        v[j].dist = d[currInd][j];
                    }
                }
            }
        }
        cout << tot << endl;
    }
    return 0;
}
