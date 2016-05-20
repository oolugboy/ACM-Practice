#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#define intMax std::numeric_limits<int>::max()
using namespace std;

class mycomparison
{
    public:
        bool operator() (pair< int, int > a, pair< int, int> b) const
        {
            return a.second > b.second;
        }
};
class Node
{
    public:
        vector< pair<int,int> > adj;
        int dist; 
        int secDist; 
        Node()
        {
            dist = intMax;
            secDist = intMax;
        }
};
int main()
{
    int n = 0, r = 0;
    cin >> n >> r;
    Node nodes[n + 1];
    bool visited[n + 1];
    typedef priority_queue< pair< int, int > ,
            vector< pair<int , int > >,mycomparison> mypq_type;
    mypq_type Q;
    for(int i = 0; i < n + 1; i++)
    {
        nodes[i] = Node();
        if(i > 0)
            Q.push(make_pair(i,intMax));
        visited[i] = false;
    }
    for(int i = 0; i < r; i++)
    {
        int s = 0, d = 0, dist = 0;
        cin >> s >> d >> dist;
        nodes[s].adj.push_back(make_pair(d,dist));
        nodes[d].adj.push_back(make_pair(s,dist));
    }
    nodes[1].dist = 0;
    Q.push(make_pair(1,0));
    while(!(Q.empty()))
    {
        pair< int,int > curr = Q.top();
        Q.pop();
        if(visited[curr.first] == false)
        {
            visited[curr.first] = true;
            nodes[curr.first].dist = curr.second;
           // cerr << " The index " << curr.first << " " << nodes[curr.first].dist <<
            //endl;
            int cDist = curr.second;
            int size = nodes[curr.first].adj.size();
            for(int i = 0; i < size; i++)
            {
                pair<int, int > a = nodes[curr.first].adj[i];  
                /* cerr << " The chal " << a.second << " elem " << a.first
                   << endl; */
                int test = cDist + a.second;
                if(test < nodes[a.first].secDist)
                {
                    if(test < nodes[a.first].dist)
                    {
                        nodes[a.first].secDist = nodes[a.first].dist;
                        nodes[a.first].dist = test;
                        Q.push(make_pair(a.first, test));
                    }
                    if(test > nodes[a.first].dist)
                    {
                        nodes[a.first].secDist = test;
                    }
                }
            }
        }
    }
    cout << nodes[n].secDist << endl;
    return 0;
}
