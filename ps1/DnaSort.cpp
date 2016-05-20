#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
    public:
        string id;
        int inv;
        Node(string id):id(id), inv(inv){}
};
int getInv(string curr, int size)
{
    int invs = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = i; j < size; j++)
        {
            if(curr[i] > curr[j])
            {
                invs++;
            }
        }
    }
    return invs;
}
bool comp(Node a, Node b)
{
    return a.inv < b.inv;
}
int main() {
    int size = 0, am = 0;
    cin >> size >> am;
    vector<Node> strs;
    string curr = "";
    for(int i = 0; i < am; i++)
    {
       cin >> curr;
       Node inst = Node(curr);
       inst.inv = getInv(curr,size);
       strs.push_back(inst);
    }
    sort(strs.begin(),strs.end(), comp);
    vector<Node>::iterator it = strs.begin();
    vector<Node>::iterator ven = strs.end();
    for(;it != ven; it++)
    {
        cout << (*it).id << endl;
    }
    return 0;
}

