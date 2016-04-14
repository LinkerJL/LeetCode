#pragma once
#include <string>
using std::string;
#include <memory>
using std::unique_ptr;
#include <numeric>
using std::accumulate;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        auto array = unique_ptr<int[]>(new int[2 * numRows - 2]);
        for (auto i = 0; i < numRows; ++i) {
            array[i] = i;
        }
        for (auto i = numRows; i < 2 * numRows - 2; ++i) {
            array[i] = 2 * numRows - 2 - i;
        }
        auto ss = unique_ptr<string[]>(new string[numRows]);
        auto len = s.size();
        for (auto i = 0; i < len; ) {
            for (auto j = 0; j < 2 * numRows - 2; ++j) {
                ss[array[j]].push_back(s[i]);
                ++i;
                if (i >= len) {
                    break;
                }
            }
        }
        return accumulate(&ss[0], &ss[numRows], string(""));
    }
};
