#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;
        for (auto i = 1; i <= rowIndex; ++i) {
            for (auto j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};
