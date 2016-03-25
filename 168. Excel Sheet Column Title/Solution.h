#pragma once
#include <string>
using std::string;
#include <algorithm>
using std::reverse;

class Solution {
public:
    string convertToTitle(int n) {
        const int letter_count = 26;
        string str;
        int m;
        while (n--) {
            str += (n % letter_count) + 'A';
            n /= letter_count;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
