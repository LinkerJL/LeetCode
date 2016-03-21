#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int len = prices.size();
        for (int i = 0; i < len - 1; i++) {
            int profit = prices[i + 1] - prices[i];
            if (profit > 0) {
                max_profit += profit;
            }
        }
        return max_profit;
    }
};
