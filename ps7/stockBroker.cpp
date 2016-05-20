#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class mycomparison
{
public:
  bool operator() (pair<int, int> a, pair<int,int> b) const
  {
      return a.second > b.second;
  }
};
int main() {
    int n = 0;    
    while(cin >> n && n != 0)
    {
        int dists[n + 1][n + 1];
        for(int i = 0; i < n + 1; i++)
            for(int j = 0; j < n + 1; j++)
                dists[i][j] = 20;

        for(int i = 1; i < n + 1; i++)
        {
            int am = 0;
            cin >> am;
            for(int j = 0; j < am; j++)
            {
                int d = 0, t = 0;
                cin >> d >> t;
                dists[i][d] = t;
            }
        }
        int minStart = 0, minDist = 20;

        for(int i = 1; i < n + 1; i++)
        {
            bool visited[n + 1];
            int nodeDists[n + 1];
            for(int m = 0; m < n + 1; m++)
            {
                visited[m] = false;
                nodeDists[m] = 20;
            }

            typedef priority_queue< pair<int,int> ,vector< pair<int,int> >,mycomparison> pqType;
            pqType Q;
            for(int j = 1; j < n + 1; j++)
            {
                Q.push(make_pair(j, 20));
            }
            Q.push(make_pair(i, 0));
            while(!(Q.empty()))
            {
                pair<int, int> curr = Q.top();
                Q.pop();
                if(visited[curr.first] == false)
                {
                    visited[curr.first] = true;
                    nodeDists[curr.first] = curr.second;
                    int index = curr.first;
                    for(int k = 1; k < (n + 1); k++)
                    {
                        if(visited[k] == false)
                        {
                            if(nodeDists[index] + dists[index][k] < nodeDists[k])
                            {
                                Q.push(make_pair(k, nodeDists[index] +
                                dists[index][k])); 
                            }
                        }
                    }
                }
            }
            int maxTime = 0;
            for(int l = 1; l < n + 1; l++)
            {
                maxTime = max(maxTime, nodeDists[l]); 
            }
            if(maxTime < minDist)
            {
                minDist = maxTime;
                minStart = i;
            }
        }
        if(minDist == 20)
            cout << "Disjoint" << endl;
        else
            cout << minStart << " " << minDist << endl;
    }
    return 0;
}
