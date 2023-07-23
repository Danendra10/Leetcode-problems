#include "include_all.h"

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int sign = 1;
        int result = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i++] == '+') ? 1 : -1;
        }
        while (i < s.length() && s[i] >= '0' && s[i] <= '9')
        {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > 7))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (s[i++] - '0');
        }
        return result * sign;
    }
};

int main()
{
    string s = "+42";
    Solution sol;
    int result = sol.myAtoi(s);
    cout << "result: " << result << endl;
}