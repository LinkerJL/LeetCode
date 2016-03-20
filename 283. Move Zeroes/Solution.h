#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = -1, zero_count = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] && i != index) {
                if (index >= 0) {
                    nums[index] = nums[i];
                    index++;
                }
            } else {
                zero_count++;
                if (index < 0) {
                    index = i;
                }
            }
        }
        for (int i = len - zero_count; i < len; i++) {
            nums[i] = 0;
        }
    }
};