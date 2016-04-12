#pragma once

class Solution {
public:
    int trailingZeroes(int n) {
        auto sum = 0;
        while (n > 0) {
            n /= 5;
            sum += n;
        }
        return sum;
    }
};
