#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
    public:
        Node * child;
        Node * par;
        char id;
        int val;
        Node(int val):val(val),id('t'){}
}; 
class Tree
{
    public:
        Node * root;
};
int sum(Node * curr)
{
    if(curr->val == 1)
    {
        return 1;
    }
    return curr->val + sum(curr->child);
}
int main() 
{
    Tree t = Tree();
    Node * curr = new Node(50000);
    t.root = curr;
    for(int i = 49999; i >= 1; i--)
    {
        Node * child = new Node(i);
        curr->child = child;
        curr = child;
    } 
    cout << sum(t.root) << endl;
    return 0;
}

