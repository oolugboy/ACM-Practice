#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void print(int row, int col, int arr * [])
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << arr[i][j] << endl;
        }
    }
}
int main() {
    int count  = 0;
    int arr[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            arr[i][j] = 19;
        }
    }
    print(arr, 4,4);
    return 0;
}
