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
            auto sorted_str = StrSort(str);
            groups[sorted_str].push_back(str);
        }
        vector<vector<string>> result;
        for (auto group : groups) {
            sort(group.second.begin(), group.second.end());
            result.push_back(group.second);
        }
        return result;
    }
private:
    string StrSort(string& str) {
        const int letter_count = 26;
        char frequency[letter_count] ={ 0 };
        int len = str.size();
        for (int i = 0; i < len; i++) {
            frequency[str[i] - 'a']++;
        }
        string sorted_str(len, 'a');
        int index = 0;
        for (int i = 0; i < letter_count; i++) {
            for (int j = 0; j < frequency[i]; j++) {
                sorted_str[index] += i;
                index++;
            }
        }
        return sorted_str;
    }
};
