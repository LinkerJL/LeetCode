#pragma once

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 10) {
            return x >= 0;
        }
        auto y = 0LL;
        auto n = x;
        while (n) {
            y = y * 10 + n % 10;
            n /= 10;
        }
        return y == x;
    }
};
