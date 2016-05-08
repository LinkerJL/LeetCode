#pragma once
#include <vector>
using std::vector;
using std::iter_swap;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto len = nums.size();
        if (len < 1 || (k %= len) == 0) {
            return;
        }
        // std::rotate(nums.begin(), nums.end() - k, nums.end());
        auto first = nums.begin();
        auto middle = nums.end() - k;
        auto next = middle;
        while (first != next) {
            iter_swap(first, next);
            ++first;
            ++next;
            if (next == nums.end()) {
                // A-B = Al-Ar-B -> B-Ar-Al => Ar-Al -> Al-Ar
                next = middle;
            } else if (first == middle) {
                // A-B = A-Bl-Br -> Bl-A-Br => A-Br -> Br-A
                middle = next;
            }
        }
    }
};
