#pragma once
#include <utility>
using std::swap;
#include <stack>
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            stack<TreeNode*> tree;
            tree.push(root);
            while (!tree.empty()) {
                TreeNode* node = tree.top();
                tree.pop();
                swap(node->left, node->right);
                if (node->left) {
                    tree.push(node->left);
                }
                if (node->right) {
                    tree.push(node->right);
                }
            }
        }
        return root;
    }
};
