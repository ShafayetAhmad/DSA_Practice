#include <iostream>
#include <vector>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, std::vector<int>& ans) {
        if (root == nullptr)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> ans;
        inorder(root, ans);
        return ans[k - 1];
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution solution;

    int k = 3;
    int kthSmallestElement = solution.kthSmallest(root, k);

    std::cout << "The " << k << "th smallest element is: " << kthSmallestElement << std::endl;

    // Clean up memory (optional, if not using smart pointers)
    // ...

    return 0;
}
