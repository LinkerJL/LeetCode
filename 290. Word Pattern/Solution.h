#pragma once
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <sstream>
using std::istringstream;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int pattern2index[26] ={ 0 };
        unordered_map<string, int> str2index;
        istringstream in(str);
        int index = 0;
        int pattern_len = pattern.size();
        for (string word; in >> word; index++) {
            int key = pattern[index] - 'a';
            if (index == pattern_len || pattern2index[key] != str2index[word]) {
                return false;
            }
            pattern2index[key] = str2index[word] = index + 1;
        }
        return index == pattern_len;
    }
};
