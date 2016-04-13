#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        for (auto i = 0; i <= rowIndex; ++i) {
            auto pre = row[0];
            for (auto j = 1; j < i; ++j) {
                auto cur = row[j];
                row[j] += pre;
                pre = cur;
            }
            row[i] = 1;
        }
        return row;
    }
};
