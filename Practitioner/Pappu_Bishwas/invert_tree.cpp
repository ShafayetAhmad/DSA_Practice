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
    TreeNode* invertTree(TreeNode* root) {
        // Base Case
        if (root == nullptr)
            return nullptr;
        invertTree(root->left); // Call the left subtree
        invertTree(root->right); // Call the right subtree
        // Swap the nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root; // Return the root
    }
};

// Helper function to print the binary tree (in-order traversal)
void printInOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    std::cout << "Original In-Order Traversal: ";
    printInOrder(root);
    std::cout << std::endl;

    TreeNode* invertedRoot = solution.invertTree(root);

    std::cout << "Inverted In-Order Traversal: ";
    printInOrder(invertedRoot);
    std::cout << std::endl;

    // Clean up memory (not necessary in LeetCode environment)
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
