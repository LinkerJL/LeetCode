#pragma once

class Solution {
public:
    bool isHappy(int n) {
        // Brent's Cycle Detection Algorithm
        int move = n, stay = 0;
        int step = 0, interval = 2;
        while (move != 1 && move != stay) {
            if (step == interval) {
                stay = move;
                interval *= 2;
                step = 0;
            }
            move = digitSquareSum(move);
            step += 1;
        }
        return move == 1;
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
