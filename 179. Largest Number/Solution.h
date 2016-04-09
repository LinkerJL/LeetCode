#pragma once
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::to_string;
#include <sstream>
using std::ostringstream;
#include <algorithm>
using std::sort;
#include <numeric>
using std::accumulate;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        bool all_zero = true;
        for (auto n : nums) {
            if (n > 0) {
                all_zero = false;
            }
            strs.push_back(to_string(n));
        }
        if (all_zero) {
            return "0";
        }
        sort(begin(strs), end(strs), [](string& a, string& b) {
            return a + b > b + a;
        });
        return accumulate(begin(strs), end(strs), string(""));
    }
};
