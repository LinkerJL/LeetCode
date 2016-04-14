#pragma once
#include <string>
using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
        auto len = s.size();
        if (numRows <= 1 || len <= numRows) {
            return s;
        }
        string result(len, '\0');
        for (auto row = 0, des = 0; row < numRows; ++row) {
            for (auto src = row; src < len; src += 2 * numRows - 2) {
                result[des] = s[src];
                ++des;
                if (0 < row && row < numRows - 1) {
                    auto mid = src + (numRows - 1 - row) * 2;
                    if (mid < len) {
                        result[des] = s[mid];
                        ++des;
                    }
                }
            }
        }
        return result;
    }
};
