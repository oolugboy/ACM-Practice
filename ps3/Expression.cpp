#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <string>
using namespace std;

class Node
{
    public:
        Node * parent;
        Node * left;
        Node * right;
        string id;
        Node(string id):id(id),parent(NULL),left(NULL),right(NULL){}
};

string reverse(string temp)
{
    int size = temp.size();
    string res = "";
    for(int i = 0; i < size; i++)
    {
        res = temp[i] + res;
    }
    return res;
}
int main() {
    int t = 0;
    cin >> t;
    while(t--)
    {
        string val = "";
        cin >> val;
        int size = val.size();
        if(size == 0)
        {
            continue;
        }
        Node * nodes[256];
       // map<string, Node *> nodes;
        for(int i = 0; i < size; i++)
        {
            string s(1, val[i]);
            Node * curr = new Node (s);             
            nodes[(int)val[i]] = curr;
        }
        stack<string> symbs;
        Node * root;
        for(int i = 0; i < size; i++)
        {
            if((int)val[i] >= 65 && (int)val[i] <= 90)
            {
                string rSymb = symbs.top();
                symbs.pop();
                string lSymb = symbs.top();
                symbs.pop();
                Node * bigV = nodes[(int)val[i]];
                Node * l = nodes[(int)lSymb[0]];
                Node * r = nodes[(int)rSymb[0]];
                l->parent = r->parent = bigV;
                bigV->left = l;
                bigV->right = r;
                if(i == (size - 1))
                {
                    root = bigV;
                }
                string res = l->id + bigV->id + r->id;
                symbs.push(bigV->id);
            }
            else
            {
                string lower(1,val[i]);
                symbs.push(lower);
            }
        }
        queue<Node *> myQ;
        myQ.push(root);
        string temp = "";
        while(!(myQ.empty()))
        {
            Node * curr = myQ.front();
            myQ.pop();
            temp += curr->id;
            if(curr->left != NULL)
            {
                myQ.push(curr->left);
            }
            if(curr->right != NULL)
            {
                myQ.push(curr->right);
            }
        }
        cout << reverse(temp) << endl;
    }
    return 0;
}
