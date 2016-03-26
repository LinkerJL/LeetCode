#pragma once
#include <cmath>
#include <climits>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n > 1) {
            static const int max_power = log(INT_MAX) / log(3);
            static const int max_3_num = pow(3, max_power);
            return (max_3_num % n == 0);
        }
        return n == 1;
    }
};
