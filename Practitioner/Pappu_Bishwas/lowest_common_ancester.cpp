#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp;
        if (root->val > p->val && root->val > q->val)
            temp = lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val)
            temp = lowestCommonAncestor(root->right, p, q);
        else
            return root;

        return temp;
    }
};

int main() {
    // Create a sample binary search tree
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution solution;
    TreeNode* p = root->left;  // Example p node
    TreeNode* q = root->right; // Example q node

    TreeNode* result = solution.lowestCommonAncestor(root, p, q);
    std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << result->val << std::endl;

    // Clean up memory (delete the tree)
    // ... (write code here to delete the tree and free memory)

    return 0;
}
