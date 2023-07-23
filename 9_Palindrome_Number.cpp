#include "include_all.h"

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long int temp = x;
        long int rev = 0;
        while (temp != 0)
        {
            long int pop = temp % 10;
            temp /= 10;
            rev = rev * 10 + pop;
        }
        return x == rev;
    }
};

int main()
{
    int x = 121;
    Solution s;
    bool result = s.isPalindrome(x);
    cout << "result: " << result << endl;
}