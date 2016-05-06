#pragma once
#include <string>
using std::string;
using std::begin;
using std::end;
using std::iter_swap;

class Solution {
public:
    string reverseString(string s) {
        auto begin_iter = begin(s);
        auto end_iter = end(s);
        while (begin_iter != end_iter && begin_iter != --end_iter) {
            iter_swap(begin_iter++, end_iter);
        }
        return s;
    }
};
