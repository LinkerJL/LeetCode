#pragma once
#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n > 1) {
            static const int max_3_num = pow(3, 19);
            return (max_3_num % n == 0);
        }
        return n == 1;
    }
};
