#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


class Node
{
    public:
        Node * par;
        Node * left;
        Node * right;
        char id;
        int p;
        Node(char id, int p):
        id(id),p(p),par(NULL),left(NULL),right(NULL){}
};
class Tree
{
    public:
        Node * root;
};

void makeTree(Node * nodes[], Tree &t, int size)
{
    t.root = divRoot(0,(size - 1),nodes);
}
Node * divRoot(int start, int end, Node * nodes[])
{
    if((end - start) == 0)
    {
        return nodes[start];
    }
    else
    {
        int mid = (end + start)/2;
        Node * lRoot = divRoot(start,(mid - 1), nodes);
        Node * rRoot = divRoot(mid,end,nodes);
        Node * parent, child, prevPar;
        if(lRoot->p >= rRoot->p)
        {
            parent = lRoot;
            child = rRoot;
        }
        else
        {
            parent = rRoot;
            child = lRoot;
        }

        while(true)
        {
            prevPar = parent;
            if((int)(child->id) > (int)(parent->id) && child->p < parent->p)
            {   
                if(parent->right)
                {
                    prevPar = parent;
                    parent = parent->right;
                }
                else
                {
                    parent->right = child;
                    break;
                }
            }
            if((int)(child->id) > (int)(parent->id) && child->p > parent->p)
            {   
                if(prevPar->right)
                {
                    parent->;
                    parent = parent->right;
                }
                else
                {
                    parent->right = child;
                    break;
                }
            }


        }
    }
}
string printTree(Node * curr)
{
    if(curr == NULL)
    {
        return "";
    }
    string leftP = "(";
    string rightP = ")";
    string divide = "/";
    stringstream ss;
    ss << curr->p;
    string p = ss.str();
    string res = leftP + printTree(curr->left) + curr->id + divide +
    p + printTree(curr->right) + rightP;
    return res;
}
void inorder(Node * curr)
{
    if(curr == NULL)
    {
        return;
    }
    inorder(curr->left);
    cout << curr->id << endl;
    inorder(curr->right);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int test = 0;
    while(true)
    {
        cin >> test;
        if(test == 0)
        {
            break;
        }
        Tree t = Tree();
        Node * nodes[test];
        for(int i = 0; i < test; i++)
        {
            string val = "";
            cin >> val;
            char id = val[0];
            int p = (int)val[2] - 48;
            nodes[i] = new Node(id,p);
        }
        makeTree(nodes, t);
        cout << printTree(t.root) << endl;
    }
    return 0;
}

