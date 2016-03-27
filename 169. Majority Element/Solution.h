#pragma once
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
