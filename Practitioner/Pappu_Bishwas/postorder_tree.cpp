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
    void postorder(std::vector<int>& ans, TreeNode *root) {
        if (root == nullptr)
            return;
        
        postorder(ans, root->left);
        postorder(ans, root->right);
        ans.push_back(root->val);
    }

    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        postorder(ans, root);
        return ans;
    }
};

int main() {
    // Construct a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    std::vector<int> result = solution.postorderTraversal(root);

    std::cout << "Postorder Traversal: ";
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
