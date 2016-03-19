#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        int cur_power_of_2 = 1, next_power_of_2 = 2;
        for (int i = 1; i <= num; i++) {
            if (i >= next_power_of_2) {
                cur_power_of_2 = next_power_of_2;
                next_power_of_2 <<= 1;
            }
            result[i] = result[i - cur_power_of_2] + 1;
        }
        return result;
    }
};
