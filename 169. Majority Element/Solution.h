#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int byte_bits = 8;
        int major = 0;
        int len = nums.size();
        for (int i = 0; i < sizeof(int) * byte_bits; i++) {
            int mask = 1 << i, bit_counts = 0;
            for (int n : nums) {
                if (n & mask) {
                    bit_counts++;
                    if (bit_counts > len / 2) {
                        major |= mask;
                        break;
                    }
                }
            }
        }
        return major;
    }
};
