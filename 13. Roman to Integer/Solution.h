#pragma once
#include <string>
using std::string;

class Solution {
public:
    int romanToInt(string s) {
        int dict['X' + 1 - 'A'] ={ 0 };
        dict['I' - 'A'] = 1;       dict['V' - 'A'] = 5;
        dict['X' - 'A'] = 10;      dict['L' - 'A'] = 50;
        dict['C' - 'A'] = 100;     dict['D' - 'A'] = 500;
        dict['M' - 'A'] = 1000;
        auto sum = 0, index = 0;
        auto len = s.size();
        while (index < len) {
            if (s[index + 1] != '\0' && dict[s[index] - 'A'] < dict[s[index + 1] - 'A']) {
                sum += dict[s[index + 1] - 'A'] - dict[s[index] - 'A'];
                index += 2;
            } else {
                sum += dict[s[index] - 'A'];
                index += 1;
            }
        }
        return sum;
    }
};
