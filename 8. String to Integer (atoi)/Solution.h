#pragma once
#include <string>
using std::string;
#include <climits>
#include <cctype>

class Solution {
public:
    int myAtoi(string str) {
        auto i = 0;
        while (isspace(str[i])) {
            ++i;
        }
        auto sign = 1;
        if (str[i] == '+' || str[i] == '-') {
            sign = (str[i] == '+') ? 1 : -1;
            ++i;
        }
        auto num = 0LL;
        while (isdigit(str[i])) {
            num = 10 * num + str[i] - '0';
            if (sign * num < INT_MIN || sign * num > INT_MAX) {
                return (sign > 0) ? INT_MAX : INT_MIN;
            }
            ++i;
        }
        return sign * num;
    }
};
