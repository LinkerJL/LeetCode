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
        inner_rotate(nums.data(), len, k);
    }
private:
    // A-B -> B-A, k = length(B)
    void inner_rotate(int* head, int len, int k) {
        if (k == 0) {
            return;
        }
        if (len - k <= k) {
            // A-B = A-Bl-Br -> Bl-A-Br, length(A) == length(Bl)
            for (auto i = 0; i < len - k; ++i) {
                iter_swap(head, head + len - k);
                ++head;
            }
            // A-Br -> Br-A
            inner_rotate(head, k, k - (len - k));
        } else {
            // A-B = Al-Ar-B -> B-Ar-Al, length(B) == length(Al)
            for (auto i = 0; i < k; ++i) {
                iter_swap(head, head + len - k);
                ++head;
            }
            // Ar-Al -> Al-Ar
            inner_rotate(head, len - k, k);
        }
    }
};
