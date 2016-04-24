#pragma once
#include <string>
using std::string;
using std::to_string;
#include <vector>
using std::vector;
using std::begin;
using std::end;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return {};
        }
        if (!(root->left || root->right)) {
            return { to_string(root->val) };
        }
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        left.insert(end(left), begin(right), end(right));
        string val = to_string(root->val) + "->";
        for (auto& str : left) {
            str = val + str;
        }
        return left;
    }
};
