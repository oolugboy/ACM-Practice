#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


class Node
{
    public:
        int val;
        Node * parent;
        Node(int val):val(val), parent(NULL){}
};
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        Node * ns[(n+1)];
        for(int i = 1; i <= n; i++)
        {
             ns[i] = new Node(i);
        }
        for(int i = 0; i < (n - 1); i++)
        {
            int par = 0, child = 0;
            cin >> par >> child;
            ns[child]->parent = ns[par];
        }
        int a = 0, b = 0;
        cin >> a >> b;
        list<int> path;
        Node * curr = ns[a];
        while(curr)
        {
            path.push_back(curr->val);
            curr = curr->parent;
        }
        curr =  ns[b];
        bool found = false;
        while(curr)
        {
            list<int>::iterator it = path.begin();
            list<int>::iterator len = path.end();
            for(;it != len; it++)
            {
                if((*it) == curr->val)
                {
                    cout << curr->val << endl;
                    found = true;
                    break;
                }
            }
            if(found)
            {
                break;
            }
            curr = curr->parent;
        }
    }
    return 0;
}

