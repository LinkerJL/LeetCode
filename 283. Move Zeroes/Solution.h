#pragma once
#include <vector>
using std::vector;
#include <algorithm>
using std::remove;
using std::fill;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto end = remove(nums.begin(), nums.end(), 0);
        fill(end, nums.end(), 0);
    }
};