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
    void inorder(TreeNode* root, std::vector<int>& ans) {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        std::vector<int> ans;
        inorder(root, ans);
        int l = 0, r = ans.size() - 1;
        while (l < r) {
            int sum = ans[l] + ans[r];
            if (sum == k)
                return true;
            else if (sum > k)
                r--;
            else
                l++;
        }
        return false;
    }
};

int main() {
    // Creating a binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution solution;
    int target = 9;
    bool hasTarget = solution.findTarget(root, target);

    if (hasTarget) {
        std::cout << "The target sum " << target << " is found in the tree." << std::endl;
    } else {
        std::cout << "The target sum " << target << " is not found in the tree." << std::endl;
    }

    // Clean up memory (not necessary in LeetCode environment)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
