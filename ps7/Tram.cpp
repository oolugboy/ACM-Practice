:#include <cmath>
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
    int n = 0, a = 0,b = 0;
    cin >> n >> a >> b;
    int map[n + 1][n + 1];
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < n + 1; j++)
        {
            if(i == j)
                map[i][j] = 0;
            else
                map[i][j] = 1000;
        }
    }
    for(int i = 1; i < n + 1; i++)
    {
        int am = 0;
        cin >> am;
        for(int k = 0; k < am; k++)
        {
            int d = 0;
            cin >> d;
            if(k == 0)
                map[i][d] = 0;
            else
                map[i][d] = 1;
        }
    }
    int dists[n+1];
    bool visited[n+1];
    for(int i = 1; i < n + 1; i++)
    {
        dists[i] = 1000;
        visited[i] = false;
    }
    typedef priority_queue< pair<int,int> ,vector< pair<int,int> >,mycomparison> pqType;
    pqType Q;
    Q.push(make_pair(a,0));
    while(!(Q.empty()))
    {
        pair<int, int> curr = Q.top();
        Q.pop();
        if(visited[curr.first] == false)
        {
            visited[curr.first] = true;
            dists[curr.first] = curr.second;
            if(curr.first == b)
            {
                break;
            }
            for(int i = 1; i < n + 1; i++)
            {
                if(visited[i] == false)
                {
                    if(dists[curr.first] + map[curr.first][i] < dists[i])
                    {
                        Q.push(make_pair(i, dists[curr.first] +
                        map[curr.first][i])); 
                    }
                }
            }
        }
    }
    if(dists[b] < 1000)
        cout << dists[b] << endl;
    else
        cout << -1 << endl;
    return 0;
}
