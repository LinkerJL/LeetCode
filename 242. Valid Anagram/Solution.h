#pragma once
#include <string>
using std::string;
#include <algorithm>
using std::sort;

class Solution {
public:
    bool isAnagram(string s, string t) {
        const int letter_count = 26;
        int balance[letter_count] ={ 0 };
        int len = s.size();
        if (len != t.size()) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            balance[s[i] - 'a']++;
            balance[t[i] - 'a']--;
        }
        for (int i = 0; i < letter_count; i++) {
            if (balance[i]) {
                return false;
            }
        }
        return true;
    }
};
