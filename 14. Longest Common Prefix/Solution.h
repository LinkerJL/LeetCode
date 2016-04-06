#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (!len) {
            return "";
        }
        if (len == 1) {
            return strs[0];
        }
        int str_len = strs[0].size();
        for (int i = 0; i < str_len; i++) {
            char c = strs[0][i];
            for (int j = 1; j < len; j++) {
                if (strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
