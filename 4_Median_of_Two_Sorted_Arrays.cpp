#include "include_all.h"

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        uint16_t size = nums1.size();
        if (size % 2 == 0)
            return (nums1[size / 2 - 1] + nums1[size / 2]) / 2.0;

        return nums1[size / 2];
    }
};

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    Solution s;
    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << "result: " << result << endl;
}