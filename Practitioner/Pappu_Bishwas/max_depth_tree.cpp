#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void maxdepthTree(TreeNode* root, int &m, int k) {
        if (root == nullptr)
            return;
        maxdepthTree(root->left, m, k + 1);
        m = std::max(m, k + 1);
        maxdepthTree(root->right, m, k + 1);
        m = std::max(m, k + 1);
    }

    int maxDepth(TreeNode* root) {
        int m = 1;
        if (root == nullptr)
            return 0;
        maxdepthTree(root, m, 1);
        return m - 1;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int depth = solution.maxDepth(root);
    std::cout << "Maximum Depth of Binary Tree: " << depth << std::endl;

    // Clean up memory (not necessary in LeetCode environment)
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
