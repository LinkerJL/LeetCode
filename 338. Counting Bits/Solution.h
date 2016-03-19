#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        for (int i = 1; i <= num; i++) {
            // one carry bit plus other fixed bits in increment of i-1.
            result[i] = result[i & (i - 1)] + 1;
        }
        return result;
    }
};
