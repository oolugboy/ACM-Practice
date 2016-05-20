#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
    public:
        Node * n = NULL;
        int nTime = -1;
        Node * w = NULL;
        int wTime = -1;
        Node * s = NULL;
        int sTime = -1;
        Node * e = NULL;
        int eTime = -1;

        int x = 0;
        int y = 0;

        int parDist = 0;
        int id
        Node(int id):id(id){}
};
int main()
{
    int nodeAm = 0;
    int roadAm = 0;
    cin >> nodeAm >> roadAm;
    unordered_map<int, Node *> nodes;
    for(int i = 1; i <= nodeAm)
    {
        Node * current = new Node(i,0);
        nodes.insert(current);
    }

    for(int i = 0; i < roadAm; i++)
    {
        int par = 0,child = 0,dist = 0;
        string dist = "";
        cin >> par >> child >> dist >> dist;
        unordered_map<int, Node *>::iterator parIt;    
        unordered_map<int, Node *>::iterator childIt;
        parIt = nodes.find(par);
        childIt = nodes.find(child);
        childIt->second->parDist = dist;




    }
    return 0;
}
