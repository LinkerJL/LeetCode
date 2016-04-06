#pragma once

class Solution {
public:
    bool isUgly(int num) {
        static int ugly_num[] ={ 2, 3, 5 };
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        for (int i = 0; i < sizeof(ugly_num) / sizeof(int); i++) {
            if (!(num % ugly_num[i])) {
                return isUgly(num / ugly_num[i]);
            }
        }
        return false;
    }
};
