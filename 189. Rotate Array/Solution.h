#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        auto iter = nums.end() - k;
        vector<int> result(iter, nums.end());
        for (auto it = nums.begin(); it != iter; ++it) {
            result.push_back(*it);
        }
        nums = result;
    }
};
