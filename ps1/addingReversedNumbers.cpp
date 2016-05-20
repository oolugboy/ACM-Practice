#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


string reverse(string val)
{
    string ret = "";
    int size = val.size();
    bool leading = true;
    for(int i = size - 1; i >= 0; i--)
    {
        if(val[i] != 48)
        {
            leading = false;
        }
        if(val[i] != 48 || leading == false)
        {
            ret += val[i];
        }
    }
    return ret;
}
void strToChar(string val, char res[])
{
    int size = val.size();
    for(int i = 0; i < size; i++)
    {
        res[i] = val[i];
    }
    res[size] = '\0';
}
string to_string(int val)
{
    stringstream ss;
    ss << val;
    return ss.str();
}
int main() {

    int n = 0;
    cin >> n;
    while(n--)
    {
        string a = "",b = "";
        cin >> a >> b;
        char aChr[BUFSIZ];
        char bChr[BUFSIZ];
        string aRev = reverse(a);
        strToChar(aRev, aChr);
        string bRev = reverse(b);
        strToChar(bRev, bChr);

        char ** endptr;
        int aInt = strtol(aChr, endptr, 10);
        int bInt = strtol(bChr, endptr, 10);
        
        cout << reverse(to_string(aInt + bInt)) << endl;
    }
    return 0;
}

