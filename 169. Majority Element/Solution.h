#pragma once
#include <vector>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //! Moore Voting Algorithm
        // Basic idea is if we cancel out each occurrence of an element e with
        // all the other elements that are different from e than e will exist
        // till end if it is a majority element.
        int major, counts = 0;
        int len = nums.size();
        for (int n : nums) {
            if (!counts) {
                major = n;
                counts = 1;
            } else if (major == n) {
                counts += 1;
            } else {
                counts -= 1;
            }
        }
        return major;
    }
};
