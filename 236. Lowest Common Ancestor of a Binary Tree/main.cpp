#include "Solution.h"
#include <iostream>

int main() {
    Solution s;
    TreeNode root(0), n1(1), n2(2), n3(3), n4(4), n5(5);
    root.left = &n1;
    root.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    n3.right = &n5;
    TreeNode *node = s.lowestCommonAncestor(&root, &n2, &n5);
    if (node) {
        std::cout << node->val << std::endl;
    } else {
        std::cout << "node not found" << std::endl;
    }
    return 0;
}