#include "include_all.h"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> char_map;
        int max_length = 0;
        int start = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (char_map.find(s[i]) != char_map.end())
            {
                start = max(start, char_map[s[i]]);
            }
            char_map[s[i]] = i;
            max_length = max(max_length, i - start);
        }
        return max_length;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution sol;
    int result = sol.lengthOfLongestSubstring(s);
    cout << "result: " << result << endl;
}