#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class comp
{
    public:
        bool operator() (pair<int , int > a, pair<int, int> b) const
        {
            return a.second > b.second;
        }
};
class Node 
{
    public:
        int id;
        int dist;
        bool visited;
        vector<int>adj;
        Node(int id):id(id), dist(2000000000),visited(false){}
};
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    map<int, Node>nodes;
    map< pair<int,int>, int> edges;
    typedef priority_queue<pair<int, int> ,vector< pair<int, int > >, comp > mypq_type;
    mypq_type Q;
    for(int i = 0; i < n; i++)
    {
        nodes.insert(make_pair((i + 1), Node(i + 1)));
        Q.push(make_pair(i + 1, 2000000000));
    }
    for(int i = 0; i < m; i++)
    {
        int s = 0, d = 0, dist = 0;
        cin >> s >> d >> dist;
        map<int, Node>::iterator src  = nodes.find(s);
        map<int, Node>::iterator dest = nodes.find(d);
        src->second.adj.push_back(d);
        dest->second.adj.push_back(s);
        map< pair<int, int>, int>::iterator test =
        edges.find(make_pair(s,d));
        if(test != edges.end())
        {
            if(dist < test->second)
            {
                edges.erase(make_pair(test->first.first, test->first.second));
                edges.erase(make_pair(test->first.second, test->first.first));
            }
            else
            {
                continue;
            }
        }
        edges.insert(make_pair(make_pair(s,d),dist));
        edges.insert(make_pair(make_pair(d,s),dist));
    }
    Q.push(make_pair(1,0));
    while(!(Q.empty()))
    {
        pair<int, int> t = Q.top();
        Q.pop();
        map<int, Node>::iterator currIt  = nodes.find(t.first);
       // cerr << " what the heck " << t.second << endl;
        if(currIt->second.visited == false)
        {
            currIt->second.dist = t.second;
           // cerr << " The curr dist " << t.second << endl;
            currIt->second.visited = true;
            int size = currIt->second.adj.size();
            for(int i = 0; i < size; i++)
            {
                map<int, Node>::iterator dest  =
                nodes.find(currIt->second.adj[i]);
                if(dest->second.visited == false)
                {
                    int s = currIt->first;
                    int d = currIt->second.adj[i];
                    int tDist = (edges.find(make_pair(s,d)))->second;
                    if(tDist < dest->second.dist)
                    {
                        dest->second.dist = tDist;
                        Q.push(make_pair(d,tDist));
                    }
                }
            }
        }
    }
    map<int, Node>::iterator mit = nodes.begin();
    map<int, Node>::iterator mend = nodes.end();
    int res = -1;
    for(;mit != mend; mit++)
    {
       // cerr << " The dist " << mit->second.dist << endl;
        if(mit->second.dist > res)
        {
            res = mit->second.dist;
        }
    }
    cout << res << endl;
    return 0;
}
