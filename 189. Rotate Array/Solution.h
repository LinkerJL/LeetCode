#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto len = nums.size();
        if (len == 0 || (k %= len) == 0) {
            return;
        }
        auto start = 0U;
        auto rotated = 0U;
        while (rotated < len) {
            auto src = start;
            auto src_val = nums[src];
            do {
                auto des = (src + k) % len;
                auto des_val = nums[des];
                nums[des] = src_val;
                src = des;
                src_val = des_val;
                ++rotated;
            } while (src != start);
            ++start;
        }
    }
};
