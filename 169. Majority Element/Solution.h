#pragma once
#include <vector>
using std::vector;
#include <algorithm>
using std::nth_element;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        nth_element(nums.begin(), nums.begin() + len / 2, nums.end());
        return nums[len / 2];
    }
};
