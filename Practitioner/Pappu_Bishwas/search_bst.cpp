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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return root;
        else if(root->val==val)
            return root;
        else if(root->val<val){
            return searchBST(root->right,val);
        }else{
            return searchBST(root->left,val);
        }
    }
};

int main() {
    // Create a binary search tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solution;

    int targetValue = 2;
    TreeNode* result = solution.searchBST(root, targetValue);

    if (result) {
        std::cout << "Node with value " << targetValue << " found." << std::endl;
    } else {
        std::cout << "Node with value " << targetValue << " not found." << std::endl;
    }

    // Clean up memory (not necessary in LeetCode environment)
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
