#include "include_all.h"

class Solution
{
public:
    bool isValid(string s)
    {
        /**
         * 1. Use a stack to store the left parentheses.
         * 2. If the current character is a left parentheses, push it into the stack.
         * 3. If the current character is a right parentheses, pop the top element from the stack.
         * 4. If the popped element is the left parentheses corresponding to the current right parentheses, continue.
         * 5. Else, return false.
         * 6. If the stack is empty, return true.
         */
        unordered_map<char, char> char_map = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}};

        stack<char> char_stack;
        for (int i = 0; i < s.length(); i++)
        {
            if (char_map.find(s[i]) != char_map.end())
            {
                char_stack.push(s[i]);
            }
            else
            {
                if (char_stack.empty())
                {
                    return false;
                }
                char top = char_stack.top();
                char_stack.pop();
                if (char_map[top] != s[i])
                {
                    return false;
                }
            }
        }
        return char_stack.empty();
    }
};

int main()
{
    string s = "()[]{l";
    Solution sol;
    bool result = sol.isValid(s);
    cout << "result: " << result << endl;
}