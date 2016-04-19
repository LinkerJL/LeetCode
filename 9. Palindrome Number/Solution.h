#pragma once

class Solution {
public:
    bool isPalindrome(int x) {
        // avoid misjudgment.
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        auto y = 0;
        // Just reverse half to avoid overflow.
        while (y < x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return (y == x || y / 10 == x);
    }
};
