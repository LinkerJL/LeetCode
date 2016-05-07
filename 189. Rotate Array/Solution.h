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
            auto des = start + len - k;
            auto tmp = nums[des];
            do {
                auto src = (des + len - k) % len;
                nums[des] = nums[src];
                des = src;
                ++rotated;
            } while (des != start);
            nums[start] = tmp;
            ++rotated;
            ++start;
        }
    }
};
