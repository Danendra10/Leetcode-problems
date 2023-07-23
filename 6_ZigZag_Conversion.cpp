#include "include_all.h"

/**
 * ZigZag Conversion
 * to do this problem, we need to understand the pattern of the zigzag
 * example:
 * PAYPALISHIRING
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * Thus, we would read it line by line: "PAHNAPLSIIGYIR"
 *
 * Explanation of below code:
 * 1. We use a vector of strings to store the characters in each row
 * 2. We use a variable to store the current row number
 * 3. We use a variable to store whether we are going down or up
 * 4. We iterate through the string, and append the current character to the current row
 * 5. If the current row is the first row or the last row, we change the direction
 * 6. We return the concatenation of all the rows
 */

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> rows(min(numRows, int(s.length())));

        uint16_t curr_row = 0;
        uint8_t is_going_down = 0;
        string result;

        for (const auto &c : s)
        {
            rows[curr_row] += c;
            if (curr_row == 0 || curr_row == numRows - 1)
                is_going_down = !is_going_down;
            curr_row += is_going_down ? 1 : -1;
        }

        for (const auto &row : rows)
        {
            result += row;
        }
        return result;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution sol;
    string result = sol.convert(s, numRows);
    cout << "result: " << result << endl;
}