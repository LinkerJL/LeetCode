#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    vector<int> nums{ 0, 0, 2, 34, 34, 4, 41, 9 };
    Solution s;
    cout << s.largestNumber(nums) << endl;
    return 0;
}