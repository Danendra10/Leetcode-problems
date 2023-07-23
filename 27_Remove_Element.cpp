#include "include_all.h"

/**
 * Input: nums = [3,2,2,3], val = 3
 * Output: 2, nums = [2,2,_,_]
 * Explanation: Your function should return k = 2, with the first two elements of nums being 2.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
 */

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution s;
    int result = s.removeElement(nums, val);
    cout << "result: " << result << endl;
    for (int i = 0; i < result; i++)
    {
        cout << nums[i] << " ";
    }
}