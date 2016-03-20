#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = -1;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] && i != index) {
                if (index >= 0) {
                    nums[index] = nums[i];
                    nums[i] = 0;
                    index++;
                }
            } else {
                if (index < 0) {
                    index = i;
                }
            }
        }
    }
};