#pragma once
#include <vector>
using std::vector;
#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> arise;
        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            auto found = arise.find(*iter);
            if (found != arise.end()) {
                arise.erase(found);
            } else {
                arise.insert(*iter);
            }
        }
        auto left = arise.begin();
        if (left == arise.end())
        {
            return 0;
        }
        return *left;
    }
};