#include <iostream>
#include <vector>

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
    void preorder(std::vector<int>& ans, TreeNode *root) {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        preorder(ans, root->left);
        preorder(ans, root->right);
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        preorder(ans, root);
        return ans;
    }
};

int main() {
    // Construct a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    std::vector<int> result = solution.preorderTraversal(root);

    std::cout << "Preorder Traversal: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Clean up the allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
