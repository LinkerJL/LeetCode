#pragma once

class Solution {
public:
    bool isHappy(int n) {
        // using the fact that 2-6 all are unhappy and
        // all unhappy number loop hits 4
        // see: https://en.wikipedia.org/wiki/Happy_number
        while (n > 6) {
            int next = 0;
            while (n) {
                next += (n % 10) * (n % 10);
                n /= 10;
            }
            n = next;
        }
        return n == 1;
    }
};
