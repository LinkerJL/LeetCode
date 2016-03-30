#include "Solution.h"
#include <iostream>

int main() {
    Solution s;
    string str = "leetcode";
    unordered_set<string> uset ={ "leet", "code" };
    std::cout << s.wordBreak(str, uset) << std::endl;
    return 0;
}