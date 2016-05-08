#pragma once
#include <vector>
using std::vector;
using std::swap;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto len = nums.size();
        if (len < 1 || (k %= len) == 0) {
            return;
        }
        // std::rotate(nums.begin(), nums.end() - k, nums.end());
        for (auto start = 0; k > 0; len -= k, start += k, k %= len) {
            for (auto i = 0; i < k; ++i) {
                swap(nums[start + i], nums[start + len - k + i]);
            }
        }
    }
};
