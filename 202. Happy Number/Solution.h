#pragma once

class Solution {
public:
    bool isHappy(int n) {
        // Floyd's Cycle Detection Algorithm
        int slow = n, fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        } while (fast != 1 && slow != fast);
        return fast == 1;
    }
private:
    int digitSquareSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
