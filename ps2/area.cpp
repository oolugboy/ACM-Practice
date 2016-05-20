#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    string test = "";
    getline(cin,test);
    int t = (int)test[0] - 48;
    while(t--)
    {
        int x = 0; int y = 0;
        pair<int,int> prevC = make_pair(0,0);
        vector< pair<int,int> > verts; 
        int prev = 0;
        string dirs = "";
        getline(cin, dirs);
        int size = dirs.size() - 1;
        int first = 0;
        for(int i = 0; i < size; i++)
        {
            int curr = (int)dirs[i] - 48;
            if(i == 0)
            {
                first = curr; 
            }
            if(curr == 8)
            {
                y++;
                if(prev != 8 and prev != 2 )  
                {
                    verts.push_back(prevC);
                }                
            }    
            if(curr == 2)
            {
                y--;
                if(prev != 8 and prev != 2)  
                {
                    verts.push_back(prevC);
                }                
            }    
            if(curr == 6)
            {
                x++;
                if(prev != 6 and prev != 4)  
                {
                    verts.push_back(prevC);
                }                
            }    
            if(curr == 4)
            {
                x--;
                if(prev != 6 and prev != 4)  
                {
                    verts.push_back(prevC);
                }                
            }    
            if(curr == 9)
            {
                x++;
                y++;
                if(prev != 1 and prev != 9)  
                {
                    verts.push_back(prevC);
                }                
            }    
            if(curr == 1)
            {
                x--;
                y--;
                if(prev != 1 and prev != 9)  
                {
                    verts.push_back(prevC);
                }                
            }    
            if(curr == 7)
            {
                x--;
                y++;
                if(prev != 7 and prev != 3)  
                {
                    verts.push_back(prevC);
                }                
            }    
            if(curr == 3)
            {
                x++;
                y--;
                if(prev != 3 and prev != 7)  
                {
                    verts.push_back(prevC);
                }                
            }
            if(i == (size - 1))
            {
                if(curr == 7 && first == 3 || curr == 3 && first == 7 ||
                        curr == 8 && first == 2 || curr == 2 && first == 8 ||
                        curr == 9 && first == 1 || curr == 1 && first == 9 ||
                        curr == 4 && first == 6 || curr == 6 && first == 4
                    || curr == first)
                {
                    verts.erase(verts.begin(),verts.begin() + 1);
                }
            }
            prevC.first = x;
            prevC.second = y;
            prev = curr;
        }
        int j = verts.size() - 1;
        int total = 0;
        for(int i = 0; i < verts.size(); i++)
        {
            total += ((verts[j].first * verts[i].second) - (verts[j].second
            * verts[i].first));
            j = i;
        }
        cout << abs(((double)total/(double)2)) << endl;
    }
    return 0;
}

