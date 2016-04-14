#pragma once
#include <tuple>
using std::tuple;
using std::make_tuple;
using std::get;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return get<0>(implLCA(root, p, q));
    }
private:
    tuple<TreeNode*, bool> implLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return make_tuple(nullptr, false);
        }
        auto left = implLCA(root->left, p, q);
        if (get<0>(left)) {
            return left;
        }
        auto right = implLCA(root->right, p, q);
        if (get<0>(right)) {
            return right;
        }
        if (get<1>(left) && get<1>(right)) {
            return make_tuple(root, false);
        }
        if ((get<1>(left) || get<1>(right)) && (root == p || root == q)) {
            return make_tuple(root, false);
        }
        return make_tuple(nullptr, root == p || root == q ||
            get<1>(left) || get<1>(right));
    }
};