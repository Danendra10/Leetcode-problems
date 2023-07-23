#include "include_all.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int price_min = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < price_min)
            {
                price_min = prices[i];
            }
            else if (prices[i] - price_min > max_profit)
            {
                max_profit = prices[i] - price_min;
            }
        }
        return max_profit;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution s;
    int result = s.maxProfit(prices);
    cout << "result: " << result << endl;
}