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
        // 1 is in the odd-th bit.
        //return (num & 0b1010101010101010101010101010101) > 0;
        return (num & 0x55555555) > 0;
    }
};
