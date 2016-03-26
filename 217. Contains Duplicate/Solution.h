#pragma once
#include <vector>
using std::vector;
#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }
};
