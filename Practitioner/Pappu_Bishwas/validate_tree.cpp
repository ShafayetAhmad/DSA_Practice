#include <iostream>
#include <vector>

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
    void InOrderTraversal(TreeNode* root, std::vector<int>& a) {
        if (root == NULL)
            return;
        
        InOrderTraversal(root->left, a);
        a.push_back(root->val);
        InOrderTraversal(root->right, a);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        std::vector<int> a;
        InOrderTraversal(root, a);

        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i] >= a[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Creating a valid binary search tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution solution;
    bool isValid = solution.isValidBST(root);

    if (isValid) {
        std::cout << "The given tree is a valid binary search tree." << std::endl;
    } else {
        std::cout << "The given tree is not a valid binary search tree." << std::endl;
    }

    // Clean up memory (not necessary in LeetCode environment)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
