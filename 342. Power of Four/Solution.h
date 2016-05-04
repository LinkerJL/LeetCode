#pragma once

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        // (num & (num - 1)) == 0 -> num is 0b0...010...0 (a power of 2).
        if ((num & (num - 1)) != 0) {
            return false;
        }
        // 4^n - 1 = (4^n + 4^(n-1) + ... + 4) - (4^(n-1) + ... + 4 + 1)
        //         = (4 - 1)(4^(n-1) + ... + 1)
        //         = 3(4^(n-1) + ... + 1)
        // 2 * 4^n - 1 = 2(4^n - 1) + 1
        //             = 2 * 3(4^(n-1) + ... + 1) + 1
        return (num - 1) % 3 == 0;
    }
};
