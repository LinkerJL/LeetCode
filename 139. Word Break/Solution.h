#pragma once
#include <string>
using std::string;
#include <unordered_set>
using std::unordered_set;
#include <vector>
using std::vector;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        // word_break[i] == true if wordBreak(s.substr(0, i), wordDict) == true
        vector<bool> word_break(len + 1, false);
        word_break[0] = true;
        for (int i = 0; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                if (!word_break[j]) {
                    continue;
                }
                string sub = s.substr(j, i - j + 1);
                if (wordDict.find(sub) != wordDict.end()) {
                    word_break[i + 1] = true;
                    break;
                }
            }
        }
        return word_break[len];
    }
};
