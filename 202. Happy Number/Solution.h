#pragma once
#include <vector>
using std::vector;
#include <set>
using std::set;

class Solution {
public:
    bool isHappy(int n) {
        set<int> path;
        while (n != 1 && path.find(n) == path.end()) {
            path.insert(n);
            vector<int> digit;
            while (n) {
                digit.push_back(n % 10);
                n /= 10;
            }
            for (auto d : digit) {
                n += d*d;
            }
        }
        return n == 1;
    }
};
