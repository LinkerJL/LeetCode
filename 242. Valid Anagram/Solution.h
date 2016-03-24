#pragma once
#include <string>
using std::string;
#include <algorithm>
using std::sort;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
