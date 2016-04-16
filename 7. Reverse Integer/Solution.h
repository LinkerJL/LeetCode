#pragma once

class Solution {
public:
    int reverse(int x) {
        auto result = 0;
        while (x) {
            auto tmp = result * 10 + x % 10;
            if (tmp / 10 != result) {
                return 0;
            }
            result = tmp;
            x /= 10;
        }
        return result;
    }
};
