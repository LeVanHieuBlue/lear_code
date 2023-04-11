// sub square matrix in matrix square.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;
int max_submatrix(vector<vector<int>>matrix, int k)
{
    int max = INT16_MIN;
    int j = matrix.size() - k + 1;
    int i = matrix.size();
    vector<vector<int>>arr_total_colums;
    arr_total_colums.resize(j+1);
    for (int index = 0;index < arr_total_colums.size();index++)
        arr_total_colums[index].resize(i+1);
    for (int y = 0; y <j ;y++)
    {
        for (int x = 0; x < matrix.size() ;x++)
        {
            for (int sum = 0;sum < k;sum++)
                arr_total_colums[y][x] += matrix[y+sum][x];
        }
    }
    for (int y = 0 ;y < j;y++)
    {
        for (int x = 0;x < i - k+ 1;x++)
        {
            int temp = 0;
            for (int sum = 0;sum < k;sum++)
                temp += arr_total_colums[y][x + sum];
            if (temp > max)max = temp;
        }
    }
    return max;
}
int main()
{
    vector<vector<int>>matrix;
    matrix = {
        {1,2,3,4,5},
        {5,3,7,2,7},
        {1,9,7,5,6},
        {2,1,9,0,6},
        {1,1,4,3,2}
    };
    //cout << arr[2][0];
    cout<<max_submatrix(matrix, 5);
}

