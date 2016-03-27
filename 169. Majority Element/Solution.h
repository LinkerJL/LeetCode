#pragma once
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n] += 1;
            if (m[n] > (len / 2)) {
                return n;
            }
        }
        return 0;
    }
};
