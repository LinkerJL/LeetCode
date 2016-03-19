#pragma once

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);
        return (left_max_depth > right_max_depth) ?
            left_max_depth + 1 : right_max_depth + 1;
    }
};