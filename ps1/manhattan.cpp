#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


void print(vector< vector<int> >&arr, int n, int caseNo)
{
    int size = (2*n) + 1;
    cout << "slice #" << caseNo << ":" << endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(j == (size - 1))
            {
                if(arr[i][j] == -1)
                {
                    cout << "." << endl;
                }
                else
                {
                    cout << arr[i][j] << endl;
                }
            }
            else
            {
                if(arr[i][j] == -1)
                {
                    cout << ".";
                }
                else
                {
                    cout << arr[i][j];
                }
            }
        }
    }
}
void fill(vector< vector<int> >&arr, int start,int n)
{
    int size = (2*n) + 1;
    list< pair<int,int> >q;
    q.push_back(make_pair(n,n));
    while(!(q.empty()))
    {
        pair<int,int> curr = q.front();
        q.pop_front();
        int x = curr.first;
        int y = curr.second;
        if(arr[x][y] < n)
        {
            if(x > 0)
            {
                if(arr[x -1][y] == -1)
                {
                    arr[x - 1][y] = arr[x][y] + 1;
                    q.push_back(make_pair(x-1,y));
                }
            }
            if(y > 0)
            {
                if(arr[x][y - 1] == -1)
                {
                    arr[x][y - 1] = arr[x][y] + 1;
                    q.push_back(make_pair(x,y-1));
                }
            }
            if(x < (size - 1))
            {
                if(arr[x+1][y] == -1)
                {
                    arr[x+1][y] = arr[x][y] + 1;
                    q.push_back(make_pair(x+1,y));
                }
            }
            if(y < (size - 1))
            {
                if(arr[x][y+1] == -1)
                {
                    arr[x][y+1] = arr[x][y] + 1;
                    q.push_back(make_pair(x,y+1));
                }
            }
        }
    }
}
void init(vector< vector<int> >&arr,int n)  
{
    int size = (2*n) + 1;
    for(int i = 0; i < size; i++)
    {   
        for(int j = 0; j < size; j++)
        {
            arr[i][j] = -1;
        }
    }   

}
int main() {
    int t = 0;
    cin >> t;
    int index = 0;
    while(index < t)
    {
        int n = 0;
        cin >> n;
        int size = (2*n) + 1;
        vector< vector<int> > arr(size, vector<int>(size));
        cout << "Scenario #" << (index + 1) << ":" << endl;
        for(int i = 1; i < (size + 1); i++)
        {
            init(arr, n);
            int start = 0;
            if(i <= (n + 1))
            {
                start = (n - i) + 1;
            }
            else
            {
                start = i - (n + 1);
            }
            arr[n][n] = start;
            fill(arr,start,n);
            print(arr,n,i);
        }
        cout << endl;
        index++;
    }
    return 0;
}
