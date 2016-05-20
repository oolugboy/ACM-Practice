#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int f = 0;
    int r = 0;
    cin >> f >> r;
    int adj[f + 1][f + 1];
    for(int i = 0; i < f + 1; i++)
        for(int j = 0; j < f + 1; j++)
            adj[i][j] = 0;

    for(int i = 0; i < r; i++)
    {
        int s = 0, d = 0;
        cin >> s >> d;
        adj[s][d] = 1;
        adj[d][s] = 1;
    }
    int res = 0;
    for(int i = 0; i < f + 1; i++)
    {
        int inDegree = 0;
        for(int j = 0; j < f + 1; j++)
        {
            if(adj[i][j] == 1)
                inDegree++;
        }
       // cerr << " The inDegree " << inDegree << endl;
        if(inDegree == 1)
           res++;
    }
    //cerr << " The res " << res << endl;
    cout << (res + 1)/2 << endl;

    return 0;
}
