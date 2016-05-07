#pragma once
#include <vector>
using std::vector;
using std::reverse;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto len = nums.size();
        if (len == 0 || (k %= len) == 0) {
            return;
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
