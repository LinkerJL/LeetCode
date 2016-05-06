#pragma once
#include <string>
using std::string;
using std::begin;
using std::end;
#include <algorithm>
using std::reverse;

class Solution {
public:
    string reverseString(string s) {
        reverse(begin(s), end(s));
        return s;
    }
};
