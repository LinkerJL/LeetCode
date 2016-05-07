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
        auto rotated = 0U;
        for (auto i = 0U; rotated < len; ++i) {
            for (auto j = (i + k) % len; j != i; j = (j + k) % len) {
                swap(nums[i], nums[j]);
                ++rotated;
            }
            ++rotated;
        }
    }
};
