#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len, 1);
        int product_from_begin = 1, product_from_end = 1;
        for (int i = 0; i < len; i++) {
            result[i] *= product_from_begin;
            product_from_begin *= nums[i];
            result[len - 1 - i] *= product_from_end;
            product_from_end *= nums[len - 1 - i];
        }
        return result;
    }
};
