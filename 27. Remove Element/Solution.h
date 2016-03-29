#pragma once
#include <vector>
using std::vector;
#include <algorithm>
using std::remove;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto pend = remove(nums.begin(), nums.end(), val);
        return nums.size() - (nums.end() - pend);
    }
};
