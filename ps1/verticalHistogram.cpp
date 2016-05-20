#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getUlt(string lines[])
{
    string ult = "";
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < lines[i].size(); j++)
        {
            if((int)lines[i][j] >= 65 && (int)lines[i][j] <= 90)
            {
                ult+=lines[i][j];
            }
        }
    }
    return ult;
}
int main() {
    string lines[4];
    for(int i = 0; i < 4; i++)
    {
        getline(cin, lines[i]);
    }
    string ult = getUlt(lines);
    int occurs[26];
    for(int i = 0; i < 26 ; i++)
    {
        occurs[i] = 0;
    }
    for(int i = 0; i < ult.size(); i++)
    {
        occurs[((int)ult[i] - 65)]++;
    }
    int max = 0;
    for(int i = 0; i < 26; i++)
    {
        if(occurs[i] > max)
        {
            max = occurs[i];
        }   
    }
    cerr << " test " << occurs[0] << endl;
    while(max--)
    {
        for(int i = 0; i < 26; i++)
        {
            if(occurs[i] >= (max + 1))
            {
                if(i == 25)
                {
                    cout << "*" << endl;
                }
                else
                {
                    cout << "* ";
                }
            }
            else
            {
                if(i == 25)
                {
                    cout << " " << endl;
                }
                else
                {
                    cout << "  ";
                }
            }
        } 
    }
    for(int i = 0; i < 26; i++)
    {
        string a = "";
        a += (i + 65);
        if(i == 25)
        {
            cout << a << endl;
        }
        else
        {
            cout << a << " ";
        }
    }
    return 0;
}
