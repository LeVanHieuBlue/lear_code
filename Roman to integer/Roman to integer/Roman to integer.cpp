// Roman to integer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int romanToInt(string s)
{
    map<char, int>hash_roman;
    vector<int> int_roman = { 1,5,10,50,100,500,1000 };
    string char_roman = "IVXLCDM";
    // add value for hash_roman
    for (int i = 0;i < int_roman.size();i++)
    {
        pair<char, int>key;
        key.first = char_roman[i];
        key.second = int_roman[i];
        hash_roman.insert(key);
    }
    int result_roman = hash_roman[s[0]];
    int temp_value = hash_roman[s[0]];
    if (s.size() == 1) return result_roman;
    for (int index = 1;index < s.size();index++)
    {
        int curr_value = hash_roman[s[index]];
        if (curr_value > temp_value)
        {
            result_roman += curr_value - (2 * (temp_value));
        }
        else result_roman += curr_value;
        temp_value = curr_value;
    }
    return result_roman;
}
int main()
{
    string s = "CM";
    cout << romanToInt(s);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
