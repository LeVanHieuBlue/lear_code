// Add Two Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
 
    ListNode(int x)
    {
        this->val = x;
        this->next = nullptr;
    }
    ListNode(int x, ListNode* next)
    {
        this->val = x;
        this->next = next;
    }
};
void sum_list(ListNode* l1, ListNode* l2, int count ,vector<int>&nums)
{
    if (l1 == nullptr && l2 == nullptr) 
    {
        if (count != 0)
            nums.push_back(count);
        return;
    }
    int number_1, number_2;
    number_1 = number_2 = 0;
    if (l1 != nullptr)
    {
        number_1 = l1->val;
        l1 = l1->next;
    }
    if (l2 != nullptr)
    {
        number_2 = l2->val;
        l2 = l2->next;
    }
    int number_main = number_1 + number_2 + count;
    count = number_main / 10;
    nums.push_back(number_main % 10);
    sum_list(l1, l2, count, nums);
}
ListNode* add_list(vector<int>nums)
{
    ListNode* l = nullptr;
    for (int i = nums.size() - 1;i >= 0;i--)
    {
        ListNode* temp = new ListNode(nums[i], l);
        l = temp;
    }
    return l;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    vector<int>nums;
    sum_list(l1, l2, 0, nums);
    ListNode* result = add_list(nums);
    return result;
}

void out_list(ListNode* l)
{
    while (l != nullptr)
    {
        cout << l->val << " ";
        l = l->next;
    }
}
int main()
{
    vector<int>nums_1 = { 1,9,8,3 };
    vector<int>nums_2 = { 9,8,1,8 };
    ListNode* l1 = add_list(nums_1);
    ListNode* l2 = add_list(nums_2);
    vector<int>nums;
    sum_list(l1, l2, 0, nums);
    for (auto i : nums)
        cout << i;
    
}

