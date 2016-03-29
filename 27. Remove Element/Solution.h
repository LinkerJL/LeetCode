#pragma once
#include <vector>
using std::vector;
#include <algorithm>
using std::remove;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (!len) {
            return 0;
        }
        int *begin = &nums[0], *end = &nums[len - 1];
        while (begin <= end) {
            while (begin <= end && *end == val) {
                end--;
            }
            while (begin <= end && *begin != val) {
                begin++;
            }
            if (begin < end) {
                *begin = *end;
                begin++;
                end--;
            }
        }
        return begin - &nums[0];
    }
};
