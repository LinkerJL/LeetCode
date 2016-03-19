#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        size_t len = nums.size();
        for (size_t i = 1; i < len; i++) {
            result ^= nums[i];
        }
        return result;
    }
};