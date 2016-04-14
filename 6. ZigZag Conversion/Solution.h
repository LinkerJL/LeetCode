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
        auto ss = unique_ptr<string[]>(new string[numRows]);
        auto len = s.size();
        auto step = 1;
        for (auto i = 0, j = 0; i < len; ++i) {
            ss[j].push_back(s[i]);
            if (j == numRows - 1) {
                step = -1;
            }
            if (j == 0) {
                step = 1;
            }
            j += step;
        }
        return accumulate(&ss[0], &ss[numRows], string(""));
    }
};
