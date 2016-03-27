#pragma once
#include <vector>
using std::vector;
#include <cstdlib>
#include <ctime>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        srand((unsigned int)time(nullptr));
        while (true) {
            int candidate = nums[rand() % len];
            int count = 0;
            for (int n : nums) {
                if (candidate == n) {
                    count++;
                    if (count > len / 2) {
                        return candidate;
                    }
                }
            }
        }
    }
};
