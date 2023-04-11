// threeSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<set>
using namespace std;

    void heap(vector<int>& arr, int i, int n)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int temp = i;
        if (left<n && arr[left]>arr[i])
            i = left;
        if (right<n && arr[right]>arr[i])
            i = right;
        if (i != temp)
        {
            swap(arr[i], arr[temp]);
            heap(arr, i, n);
        }
    }
    void Heap_sort(vector<int>& arr)
    {
        int n = arr.size();
        for (int i = (n - 1) / 2; i >= 0; i--)
            heap(arr, i, n);
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heap(arr, 0, i);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>>result;
        set<vector<int>>convert_result;
        vector<int>exactly;
        Heap_sort(nums);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int temp = nums[left] + nums[right];
                if (temp + nums[i] > 0) right--;
                else if (temp + nums[i] < 0)left++;
                else
                {
                    exactly.push_back(nums[i]);
                    exactly.push_back(nums[left]);
                    exactly.push_back(nums[right]);
                    convert_result.insert(exactly);
                    exactly.clear();
                    if (right > 0)right--;
                    else if (left < nums.size())left++;
                    else break;
                }
                if (left == right)break;
            }

        }
        for (auto i : convert_result)
            result.push_back(i);
        return result;
    }
int main()
{
    vector<int>nums = { -2,0,1,1,2 };
    for (auto i : threeSum(nums))
    {
        for (int j = 0;j < i.size();j++)
            cout << i[j] << " ";
        cout << endl;
    }
}

