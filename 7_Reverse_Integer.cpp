#include "include_all.h"

/**
 * 1. 32-bit signed integer range: [-2^31, 2^31 - 1]
 * 2. 64-bit signed integer range: [-2^63, 2^63 - 1]
 * 3. 32-bit unsigned integer range: [0, 2^32 - 1]
 * 4. 64-bit unsigned integer range: [0, 2^64 - 1]
 *
 * Example we have an input x = 123, we want to reverse it to 321.
 * we could pop the last digit of x by x % 10, and push it to the end of reversed.
 */

class Solution
{
public:
    int reverse(int x)
    {
        int reversed = 0;
        while (x != 0)
        {
            int popped = x % 10;                                                      // in: 123, popped = 3
            x /= 10;                                                                  // in: 123, x = 12 bcs x is int
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && popped > 7))  // INT_MAX = 2147483647, it means the max value of reversed is 214748364, if reversed is 214748364, the max value of popped is 7.
                return 0;                                                             // we will return 0 if reversed is 214748364 and popped is 8.
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && popped < -8)) // INT_MIN = -2147483648, it means the min value of reversed is -214748364, if reversed is -214748364, the min value of popped is -8.
                return 0;                                                             // we will return 0 if reversed is -214748364 and popped is -9.
            reversed = reversed * 10 + popped;                                        // out: 3, reversed = 3, then out: 2, reversed = 32, then out: 1, reversed = 321
        }
        return reversed;
    }
};

int main()
{
    int x = 123;
    Solution s;
    int result = s.reverse(x);
    cout << "result: " << result << endl;
}