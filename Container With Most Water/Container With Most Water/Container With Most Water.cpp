// Container With Most Water.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int result = 0;
    int temp = 0;
    while (left < right)
    {
        int a = min(height[left], height[right]);
        int b = right - left;
        temp = a * b;
        if (temp > result)result = temp;
        if (height[left] > height[right])right--;
        else left++;
    }
    return result;
}
int main()
{
    vector<int>nums = { 1,1 };
    cout << maxArea(nums);
}

