#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> prev;
        queue<TreeNode*> curr;
        
        if (root == nullptr)
            return ans;

        TreeNode *temp;
        prev.push(root);
    
        while (!prev.empty()) {
            vector<int> t; // Create a new vector for each level
           
            while (!prev.empty()) {
                temp = prev.front();
                if (temp->left != nullptr)
                    curr.push(temp->left);
                if (temp->right != nullptr)
                    curr.push(temp->right);
                t.push_back(temp->val);
                prev.pop();
            }
            
            ans.push_back(t);
            prev.swap(curr); // Swap contents of prev and curr queues
        }
        
        return ans;
    }
};
