#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
#define maxInt numeric_limits<int>::max()

class Edge
{
    public:
        int s;
        int d;
        int t;
        Edge(int s, int d, int t):s(s),d(d),t(t){}
        Edge(){}
};
int main() {
    int f = 0;
    cin >> f;
    while(f--)
    {
        int n = 0, m = 0,w = 0;
        cin >> n >> m >> w;
        Edge e[((2 * m) + w)];
        int index = 0;
        for(int i = 0; i < m; i++)
        {
            int s = 0, d = 0, t = 0;
            cin >> s >> d >> t;
            e[index] = Edge(s,d,t);
            e[index + 1] = Edge(d,s,t);
            index += 2;
        }
        for(int i = 0; i < w; i++)
        {
            int s = 0, d = 0, t = 0;
            cin >> s >> d >> t;
            e[index] = Edge(s,d, (t * -1));
            index++;
        }
        for(int count = 1; count < n + 1; count++)
        {
            int prevDist[n + 1];
            int nodeDist[n + 1];
            for(int i = 0; i < n + 1; i++)
            {
                prevDist[i] = nodeDist[i] = maxInt;
            }
            prevDist[count] = nodeDist[count] = 0;
            for(int i = 1; i < n + 1; i++)
            {
                int changes = 0;
                for(int j = 0; j < ((2 * m) + w); j++)
                {
                    if(prevDist[(e[j].s)] < maxInt)
                    {
                        if((prevDist[(e[j].s)] + e[j].t) < nodeDist[(e[j].d)])
                        {
                            changes++;
                            if(i == n)
                            {
                                cout << "YES" << endl;
                                goto end;
                            }
                            nodeDist[(e[j].d)] = prevDist[(e[j].s)] +
                            e[j].t;
                        }
                    }
                }
                if(changes == 0)
                    break;
                for(int j = 1; j < n + 1; j++)
                {
                    prevDist[j] = nodeDist[j];
                }
            }
        }
        cout << "NO" << endl;
        end:
            continue;
    }
    return 0;
}
