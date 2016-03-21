#pragma once
#include <vector>
using std::vector;
#include <numeric>
using std::partial_sum;
#include <functional>
using std::multiplies;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int *forward_product = new int[len + 1];
        int *backward_product = new int[len + 1];
        forward_product[0] = 1;
        partial_sum(nums.cbegin(), nums.cend(), forward_product + 1,
            multiplies<int>());
        backward_product[0] = 1;
        partial_sum(nums.crbegin(), nums.crend(), backward_product + 1,
            multiplies<int>());
        vector<int> result(len);
        for (int i = 0; i < len; i++) {
            result[i] = forward_product[i] * backward_product[len - 1 - i];
        }
        delete[] forward_product;
        delete[] backward_product;
        return result;
    }
};
