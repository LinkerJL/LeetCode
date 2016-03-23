#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
using std::sort;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto str : strs) {
            auto sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            groups[sorted_str].push_back(str);
        }
        vector<vector<string>> result;
        for (auto group : groups) {
            sort(group.second.begin(), group.second.end());
            result.push_back(group.second);
        }
        return result;
    }
};
