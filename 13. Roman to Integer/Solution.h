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
        auto len = s.size();
        auto sum = (len > 0) ? dict[s[len - 1] - 'A'] : 0;
        for (int i = len - 2; i >= 0; --i) {
            if (dict[s[i] - 'A'] < dict[s[i + 1] - 'A']) {
                sum -= dict[s[i] - 'A'];
            } else {
                sum += dict[s[i] - 'A'];
            }
        }
        return sum;
    }
};
