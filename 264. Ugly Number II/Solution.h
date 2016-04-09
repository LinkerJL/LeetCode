#pragma once
#include <vector>
using std::vector;
#include <algorithm>
using std::min;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_nums(1, 1);
        int index_2 = 0, index_3 = 0, index_5 = 0;
        while (n > 1) {
            n--;
            int nums = min(ugly_nums[index_2] * 2, ugly_nums[index_3] * 3);
            nums = min(ugly_nums[index_5] * 5, nums);
            index_2 += (nums == ugly_nums[index_2] * 2);
            index_3 += (nums == ugly_nums[index_3] * 3);
            index_5 += (nums == ugly_nums[index_5] * 5);
            ugly_nums.push_back(nums);
        }
        return ugly_nums.back();
    }
};
