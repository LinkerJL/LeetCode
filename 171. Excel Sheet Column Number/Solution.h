#pragma once
#include <string>
using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        const int letter_count = 26;
        int num = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            num *= letter_count;
            num += s[i] - 'A' + 1;
        }
        return num;
    }
};
