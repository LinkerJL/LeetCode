#pragma once
#include <string>
using std::string;
#include <stack>
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        char trick[] = { ')', ']', '}' };
        stack<char> matching;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                matching.push((c / '(') - 1);
            } else if (matching.empty()) {
                return false;
            } else if (c != trick[matching.top()]) {
                return false;
            } else {
                matching.pop();
            }
        }
        return matching.empty();
    }
};
