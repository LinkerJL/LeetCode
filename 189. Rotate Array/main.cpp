#include <iostream>
#include "Solution.h"

int main() {
    vector<int> a = { 1,2,3,4,5,6 };
    Solution s;
    s.rotate(a, 4);
    for (auto val : a) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    return 0;
}
