#pragma once
#include <string>
using std::string;
#include <climits>

class Solution {
public:
    int myAtoi(string str) {
        auto sign = 0;
        auto num = 0LL;
        for (auto c : str) {
            if (c == ' ' || c == '\t') {
                if (sign) {
                    break;
                }
            } else if (c == '+' || c == '-') {
                if (sign) {
                    break;
                }
                sign = (c == '+') ? 1 : -1;
            } else if ('0' <= c && c <= '9') {
                if (!sign) {
                    sign = 1;
                }
                num = 10 * num + c - '0';
                if (sign * num < INT_MIN || sign * num > INT_MAX) {
                    return (sign > 0) ? INT_MAX : INT_MIN;
                }
            } else {
                break;
            }
        }
        return sign * num;
    }
};
