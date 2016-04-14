#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <numeric>
using std::accumulate;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ss(numRows);
        auto len = s.size();
        auto func = [&](int& i, int j) -> bool {
            ss[j].push_back(s[i]);
            ++i;
            return i >= len;
        };
        auto down = true;
        for (auto i = 0; i < len; ) {
            if (down) {
                for (auto j = 0; j < numRows; ++j) {
                    if (func(i, j)) {
                        break;
                    }
                }
            } else {
                for (auto j = numRows - 2; j > 0; --j) {
                    if (func(i, j)) {
                        break;
                    }
                }
            }
            down = !down;
        }
        return accumulate(ss.begin(), ss.end(), string(""));
    }
};
