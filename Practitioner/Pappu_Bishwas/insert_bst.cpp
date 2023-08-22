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
    void insert(TreeNode* root, int v) {
        if (root->val > v) {
            if (root->left == NULL)
                root->left = new TreeNode(v);
            else
                insert(root->left, v);
        }
        if (root->val < v) {
            if (root->right == NULL)
                root->right = new TreeNode(v);
            else
                insert(root->right, v);
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* newRoot = new TreeNode(val);
            return newRoot;
        }
        insert(root, val);
        return root;
    }
};

// Helper function to print the tree in-order
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    std::cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    Solution solution;
    TreeNode* newRoot = solution.insertIntoBST(root, 5);

    std::cout << "In-order traversal of the new tree: ";
    inOrderTraversal(newRoot);
    std::cout << std::endl;

    // Clean up memory (not necessary in LeetCode environment)
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
