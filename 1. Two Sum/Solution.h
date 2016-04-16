#pragma once
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> all_needs;
        auto len = nums.size();
        for (auto i = 0; i < len; ++i) {
            if (all_needs.find(nums[i]) != end(all_needs)) {
                return{ all_needs[nums[i]], i };
            }
            auto new_need = target - nums[i];
            all_needs[new_need] = i;
        }
        return{};
    }
};
