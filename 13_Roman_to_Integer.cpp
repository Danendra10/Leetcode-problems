#include "include_all.h"

unordered_map<string, int> roman_to_int_map = {
    {"I", 1},
    {"IV", 4},
    {"V", 5},
    {"IX", 9},
    {"X", 10},
    {"XL", 40},
    {"L", 50},
    {"XC", 90},
    {"C", 100},
    {"CD", 400},
    {"D", 500},
    {"CM", 900},
    {"M", 1000}};

class Solution
{
public:
    int romanToInt(string s)
    {
        char string_collection[s.length() + 1];
        strcpy(string_collection, s.c_str());
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            string temp = "";
            temp += string_collection[i];
            if (i + 1 < s.length())
            {
                temp += string_collection[i + 1];
            }
            if (roman_to_int_map.find(temp) != roman_to_int_map.end())
            {
                result += roman_to_int_map[temp];
                i++;
            }
            else
            {
                temp = "";
                temp += string_collection[i];
                result += roman_to_int_map[temp];
            }
        }
        return result;
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution sol;
    int result = sol.romanToInt(s);
    cout << "result: " << result << endl;
}