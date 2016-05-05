#pragma once
#include <vector>
using std::vector;
#include <numeric>
using std::partial_sum;

class NumArray {
public:
    NumArray(vector<int> &nums) : pre_sum(nums.size() + 1, 0) {
        partial_sum(begin(nums), end(nums), begin(pre_sum) + 1);
    }

    int sumRange(int i, int j) {
        return pre_sum[j + 1] - pre_sum[i];
    }

private:
    vector<int> pre_sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
