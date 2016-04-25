#pragma once
#include <string>
using std::string;
#include <stack>
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        if (s == "") {
            return true;
        }
        char match[256] = { 0 };
        match['('] = ')';
        match['{'] = '}';
        match['['] = ']';
        stack<char> matching;
        matching.push(s[0]);
        auto len = s.length();
        for (auto i = 1U; i < len; ++i) {
            if (matching.empty() || match[matching.top()] != s[i]) {
                matching.push(s[i]);
            } else {
                matching.pop();
            }
        }
        return matching.empty();
    }
};
