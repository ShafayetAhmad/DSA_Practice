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
    TreeNode* solver(vector<int>& nums, int s, int e) {
        if (s > e) {
            return nullptr;
        }
        int mid = (s + e) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = solver(nums, s, mid - 1);
        node->right = solver(nums, mid + 1, e);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solver(nums, 0, nums.size() - 1);
    }
};

// Function to print the inorder traversal of a binary tree (used for verification)
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Solution solution;
    
    // Create a sorted array
    std::vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = solution.sortedArrayToBST(nums);

    // Print the inorder traversal of the resulting binary search tree
    inorderTraversal(root);
    std::cout << std::endl;

    // Clean up memory (delete the tree)
    // ... (write code here to delete the tree and free memory)

    return 0;
}
