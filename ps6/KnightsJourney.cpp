#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

class Board
{
    public:
        bool squares[1024][1024];
        Board(int row, int col)
        {
            squares[row][col];
        }
};
string explore(Board &b, int moves, int targ, int
dx[], int dy[], int x, int y,int p, int q)
{
  //  cout << " in here 3" << endl;
    b.squares[x][y] = true;
    moves++;
   // cout << s << " on move " << moves << " " << targ << endl;
    if(moves == targ)
    {
        string res = "";
        res += string(1,y + 65);
        res += string(1,x + 49);
        return res;
    }

    for(int i = 0; i < 8; i++)
    {
        int ti = x + dx[i];
        int tj = y + dy[i];
        if(ti < 0 || ti >= p || tj < 0 || tj >= q || b.squares[ti][tj] ==
            true)
        {
            continue;
        }
       // cerr << " In here ever " << endl;
        //   cerr << " source " << x << " " << y << " passed " << ti << " " << tj
        // << endl;
        string res = explore(b, moves,targ,dx,dy,ti,tj,p,q);
        if(res.compare("") != 0)
        {
            // cout << " in here 6" << endl;
            string add = "";
            add += string(1,y + 65);
            add += string(1,x + 49);
            res = add + res;
            return res;
        }
    }
    // cout << " in here 4" << endl;
    b.squares[x][y] = false;
    return ""; 
}
int main() {
    int t = 0;
    cin >> t;
    int index = 0;
    while(index < t)
    {
        index++;
        int p = 0, q = 0;
        cin >> p >> q;
        Board b = Board(p,q);
        for(int i = 0; i < p; i++)
        {
            for(int j = 0; j < q; j++)
            {
                b.squares[i][j] = false;
            }
        } 
        bool reached = false;
        cout << "Scenario #" << index << ":" << endl;// p << " " << q << endl;
        int di[] = {-1,1,-2,2,-2,2,-1,1};
        int dj[] = {-2,-2,-1,-1,1,1,2,2};
        string res = explore(b,0,(p*q),di,dj,0,0,p,q);
        //cerr << " returned " << endl;
        if(res.compare("") != 0)
        {
            cout << res << endl;
            cout << endl;
            //  cerr << " in here 1" << endl;
            reached = true;
        }
        if(reached == false)
        {
            cout << "impossible" << endl;
            cout << endl;
        }
    }
    return 0;
}

