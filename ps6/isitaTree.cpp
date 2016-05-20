#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int caseNo = 1;
    while(true)
    {
        int s = 0, d = 0;
        map<int, int> nodes;
        map<int, int>::iterator it;
        map<int, int>::iterator mend;
        while(true)
        {
            cin >> s >> d;
            if(s == 0 && d == 0)
            {
                break;
            }
            if(s < 0 && d < 0)
            {
                return 0;
            }
            it = nodes.find(s);
            if(it == nodes.end())
            {
                nodes.insert(make_pair(s,0));
            }
            it = nodes.find(d);
            if(it != nodes.end())
            {
                it->second++;
            }
            else
            {
                nodes.insert(make_pair(d,1));
            }
        }
        bool tree = true;
        int roots = 0;
        it = nodes.begin();
        mend = nodes.end();
        for(;it != mend; it++)
        {
            if(it->second == 0)
            {
                roots++;
            }
            if(it->second != 0 && it->second != 1)
            {
                tree = false;
            }
        }
        if(roots != 1)
        {
            tree = false;
        }
        if(nodes.size() == 0)
        {
            tree = true;
        }
        if(tree)
        {
            cout << "Case " << caseNo << " is a tree." << endl;
        }
        else
        {
            cout << "Case " << caseNo << " is not a tree." << endl;
        }
        caseNo++;
        nodes.clear();
    }
    return 0;
}
