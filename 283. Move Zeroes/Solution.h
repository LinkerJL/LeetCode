#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i]) {
                nums[j++] = nums[i];
            }
        }
        while (j < len) {
            nums[j++] = 0;
        }
    }
};