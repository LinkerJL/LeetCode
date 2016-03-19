#pragma once

class Solution
{
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        int result = num % 9;
        if (result) {
            return result;
        }
        return 9;
    }
};
