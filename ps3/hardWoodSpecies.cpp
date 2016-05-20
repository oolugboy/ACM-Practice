#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;


int main()
{
    int total = 0;
    map<char *, int> trees;
    while(true)
    {
        char val[BUFSIZ];
        int size = scanf("%[^\n]",val);
        char nl;
        scanf("%c",&nl);
       // cerr << " The val " << val << " " << size << endl;
        //cerr <<  " at eof " << (size == EOF) << endl;
        if(size == 0 || size == EOF)
        {
            break;
        }        
        total++;
        cerr << " The val " << val << endl;
        map<char *, int>::iterator found = trees.find(val);
        if(found == trees.end())
        {
            cerr << " In here " << endl;
            trees.insert(make_pair(val,1));
        }
        else
        {
            found->second++;
        } 
    }
  //  cerr << " The total is " << total << endl;
    map<char *, int>::iterator it = trees.begin();
    map<char *, int>::iterator mend = trees.end();
    cerr << " The size " << trees.size();
    for(;it != mend; it++)
    {
        double pcent = (((double)it->second/(double)total) * (double)100);
        cout << it->first << " " << fixed << setprecision(4) << pcent << endl;
    } 
}

