#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};

void createTree(TreeNode*& root) {
    int temp;
    std::cin >> temp;

    if (temp != -1) {
        root = new TreeNode;
        root->val = temp;
        createTree(root->left);
        createTree(root->right);
    }
}

void printTree(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->val << std::endl;
        printTree(root->left);
        printTree(root->right);
    }
}

class Solution {
public:
    void dfs(std::string s, TreeNode* node, std::vector<std::string>& ans) {
        if (!node->left && !node->right) {
            ans.push_back(s);
            return;
        }

        if (node->left) {
            dfs(s + "->" + std::to_string(node->left->val), node->left, ans);
        }
        
        if (node->right) {
            dfs(s + "->" + std::to_string(node->right->val), node->right, ans);
        }
    }

    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ans;
        std::string s = std::to_string(root->val);
        dfs(s, root, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = nullptr;
    createTree(root);
    // printTree(root);
    Solution so;
    std::vector<std::string> ans = so.binaryTreePaths(root);
    for (auto s : ans) {
        std::cout << s << std::endl;
    }
}