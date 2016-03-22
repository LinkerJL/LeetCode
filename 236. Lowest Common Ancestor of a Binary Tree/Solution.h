#pragma once
#include <deque>
using std::deque;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    typedef deque<TreeNode*> Path;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool found_p = false, found_q = false;
        Path path, path_to_p, path_to_q;
        if (!depthFirstSearch(root, p, q,
            found_p, found_q, path, path_to_p, path_to_q)) {
            return nullptr;
        }
        TreeNode *ancestor = nullptr;
        while (!path_to_p.empty() && !path_to_q.empty() &&
            path_to_p.front() == path_to_q.front()) {
            ancestor = path_to_p.front();
            path_to_p.pop_front();
            path_to_q.pop_front();
        }
        return ancestor;
    }
private:
    bool depthFirstSearch(TreeNode* node, TreeNode* p, TreeNode* q,
        bool& found_p, bool& found_q,
        Path& path, Path& path_to_p, Path& path_to_q) {
        path.push_back(node);
        if (node == p) {
            found_p = true;
            path_to_p = path;
            if (found_q) {
                return true;
            }
        }
        if (node == q) {
            found_q = true;
            path_to_q = path;
            if (found_p) {
                return true;
            }
        }
        if (node->left && depthFirstSearch(node->left, p, q, found_p, found_q,
            path, path_to_p, path_to_q)) {
            return true;
        }
        if (node->right && depthFirstSearch(node->right, p, q, found_p, found_q,
            path, path_to_p, path_to_q)) {
            return true;
        }
        path.pop_back();
        return false;
    }
};