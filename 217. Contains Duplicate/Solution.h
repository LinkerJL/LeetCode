#pragma once
#include <vector>
using std::vector;
#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) {
            if (s.find(n) != s.end()) {
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};
