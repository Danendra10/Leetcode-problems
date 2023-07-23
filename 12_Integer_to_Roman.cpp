#include "include_all.h"

unordered_map<int, string> int_to_string_roman_map = {
    {1, "I"},
    {4, "IV"},
    {5, "V"},
    {9, "IX"},
    {10, "X"},
    {40, "XL"},
    {50, "L"},
    {90, "XC"},
    {100, "C"},
    {400, "CD"},
    {500, "D"},
    {900, "CM"},
    {1000, "M"}};

class Solution
{
public:
    string intToRoman(int num)
    {
        string result = "";
        vector<pair<int, string>> sorted_map(int_to_string_roman_map.begin(), int_to_string_roman_map.end());
        sort(sorted_map.rbegin(), sorted_map.rend());

        for (const auto &entry : sorted_map)
        {
            while (num >= entry.first)
            {
                result += entry.second;
                num -= entry.first;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    int num = 1994;
    string result = s.intToRoman(num);
    cout << result << endl; // Output: "MCMXCIV"
    return 0;
}
