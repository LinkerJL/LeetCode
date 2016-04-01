#pragma once
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> pattern_to_str;
        unordered_map<string, char> str_to_pattern;
        int pattern_len = pattern.size();
        int str_len = str.size();
        if (!pattern_len && str_len) {
            return false;
        }
        for (int i = 0, k = 0; i < pattern_len; i++, k++) {
            int begin = k;
            while (k < str_len && str[k] != ' ') {
                k++;
            }
            if ((i == pattern_len - 1) ^ (k == str_len)) {
                return false;
            }
            string sub = str.substr(begin, k - begin);
            auto it1 = pattern_to_str.find(pattern[i]);
            auto it2 = str_to_pattern.find(sub);
            if (it1 == pattern_to_str.end() && it2 == str_to_pattern.end()) {
                pattern_to_str[pattern[i]] = sub;
                str_to_pattern[sub] = pattern[i];
            } else if (it1 != pattern_to_str.end() && it2 != str_to_pattern.end()) {
                if (it1->second != sub) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
