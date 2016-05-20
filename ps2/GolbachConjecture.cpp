:#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    while(true)
    {
        int n = 0;
        cin >> n;
        if(n==0)
        {
            break;
        }
        int vals[n];

        for(int i = 0; i < n; i++)
        {
            vals[i] = i;
        }
        int root = sqrt(n);
        for(int i = 2; i <= root; i++)
        {
            for(int j = pow(vals[i],2); j < n; j+= vals[i])
            {
                if(vals[i] != -1)
                {
                    if(j!=i)
                    {
                        vals[j] = -1;
                    }
                }
                else
                {
                    break;
                }
            }   
        } 
        vector<int>primes;
        for(int i = 3; i < n; i++)
        {
            if(vals[i] != -1)
            {
               // cerr << " The primes " << vals[i] << endl;
                primes.push_back(vals[i]);
            }
        }
        vector<int>::iterator it = primes.begin();
        vector<int>::iterator ven = primes.end();
        int resA = -1;
        int resB = -1;
        int diff = -1;
        for(;it != ven; it++)
        {
           vector<int>::iterator inIt = primes.begin();
           for(;inIt != ven; inIt++)
           {
                if((*it) + (*inIt) == n)
                {
                    if(abs((*it) - (*inIt)) > diff)
                    {
                        resA = (*it);
                        resB = (*inIt);
                        diff =  abs((*it) - (*inIt));
                    }
                }

           }
        }
        if(resA == -1)
        {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
        else
        {
            cout << n << " = " << resA << " + " << resB << endl;
        }
    }
    return 0;
}
