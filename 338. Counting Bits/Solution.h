#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        for (int i = 1; i <= num; i++) {
            result[i] = result[i >> 1] + (i & 0x01);
        }
        return result;
    }
};
