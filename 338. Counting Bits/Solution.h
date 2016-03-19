#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        for (int i = 0; i <= num; i++) {
            int j = i, k = 0;
            while (j > 0) {
                k += j & 0x01;
                j >>= 1;
            }
            result[i] = k;
        }
        return result;
    }
};
