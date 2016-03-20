#pragma once
#include <vector>
using std::vector;
#include <numeric>
using std::accumulate;
#include <functional>
using std::bit_xor;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int two_xor = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int last_set_bit = two_xor & (-two_xor);
        vector<int> result ={ 0, 0 };
        for (int num : nums) {
            if (num & last_set_bit) {
                result[0] ^= num;
            }
        }
        result[1] = two_xor ^ result[0];
        return result;
    }
};