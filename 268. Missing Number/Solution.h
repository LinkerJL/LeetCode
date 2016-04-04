#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int result = len;
        for (int i = 0; i < len; i++) {
            result ^= i ^ nums[i];
        }
        return result;
    }
};
