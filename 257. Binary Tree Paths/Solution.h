#pragma once
#include <string>
using std::string;
using std::to_string;
#include <vector>
using std::vector;

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
            return{};
        }
        paths.clear();
        string head = "";
        DFS(root, head);
        return paths;
    }
private:
    void DFS(TreeNode* node, string& path) {
        string new_path = path + "->" + to_string(node->val);
        if (!(node->left || node->right)) {
            paths.push_back(new_path.substr(2));
            return;
        }
        if (node->left) {
            DFS(node->left, new_path);
        }
        if (node->right) {
            DFS(node->right, new_path);
        }
    }

    vector<string> paths;
};
