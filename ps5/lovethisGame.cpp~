#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void sort(int vals[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = vals[(left + right) / 2];
 
      while (i <= j) 
      {
            while (vals[i] < pivot)
            {
                  i++;
            }
            while (vals[j] > pivot)
            {
                  j--;
            }
            if (i <= j) 
            {
                  tmp = vals[i];
                  vals[i] = vals[j];
                  vals[j] = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
      {
            sort(vals, left, j);
      }
      if (i < right)
      {
            sort(vals, i, right);
      }
}
int getDiff(int currVal, int pos, int vals[], int n, map<int,int> &diffs, int a,
int b)
{
    map<int,int>::iterator found;
    found = diffs.find(currVal);
    if(n - pos <= 1)
    {
        diffs.insert(make_pair(currVal,currVal));
        return currVal;
    }
    if(found == diffs.end())
    {
        int diff = 10000000;
        int vMoves = 0;
        for(int i = pos; i < n; i++)
        {
            int next = 0;
            if(vals[i] - currVal >= a && vals[i] - currVal <= b)
            {
                vMoves++;
                found = diffs.find(vals[i]);
                if(found == diffs.end())
                {
                    next = getDiff(vals[i],i + 1, vals,n,diffs,a,b);
                }
                else
                {
                    next = found->second;
                }
                diff = min(diff, currVal - next);
            }
        }
        if(vMoves == 0)
        {
            diff = 0;
        }
        diffs.insert(make_pair(currVal,diff));
        return diff;
    }
    else
    {
        return found->second;
    }
}
int main() 
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, a = 0, b = 0;
        cin >> n >> a >> b;
        int vals[n];
        for(int i = 0; i < n; i++)
        {
            cin >> vals[i];
        }
        sort(vals, 0, n - 1);
        map<int, int> diffs;
        int res = -100000000;
        int vMoves = 0;
        for(int i = 0; i < n; i++)
        {
            if(vals[i] >= a && vals[i] <= b)
            {
                vMoves++;
                int temp = res;
                res = max(res,getDiff(vals[i],i+1,vals,n,diffs,a,b));
            }
        }
        cout << ((vMoves == 0)? 0 : res) << endl;
    }
    return 0;
}


