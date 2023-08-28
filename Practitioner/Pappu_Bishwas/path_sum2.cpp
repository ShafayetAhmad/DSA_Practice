#include <iostream>
#include <vector>

using namespace std;

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
    void findpath(TreeNode* root, vector<vector<int>>& ans, vector<int>& curr, int target) {
        if (root == nullptr) {
            return;
        }
        
        if (root->left == nullptr && root->right == nullptr && target - root->val == 0) {
            curr.push_back(root->val);
            ans.push_back(curr);
            curr.pop_back();
        } else if (root->left == nullptr && root->right == nullptr) {
            return;
        }
        
        curr.push_back(root->val);
        findpath(root->left, ans, curr, target - root->val);
        findpath(root->right, ans, curr, target - root->val);
        curr.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        if (root == nullptr) {
            return ans;
        }
        
        findpath(root, ans, curr, targetSum);
        return ans;
    }
};

int main() {
    // Create your binary tree here
    // TreeNode* root = ...;

    // Create an instance of the Solution class
    Solution solution;

    // Call the pathSum function and pass the root node and target sum
    vector<vector<int>> result = solution.pathSum(root, targetSum);

    // Print the result
    for (const vector<int>& path : result) {
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
