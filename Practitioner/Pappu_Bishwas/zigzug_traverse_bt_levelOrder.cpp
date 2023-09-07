#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // For reverse

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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        std::queue<TreeNode*> prev;
        std::queue<TreeNode*> curr;
        int c = 0;

        if (root == nullptr)
            return ans;

        TreeNode* temp;
        prev.push(root);

        while (!prev.empty()) {
            std::vector<int> t; // Create a new vector for each level

            while (!prev.empty()) {
                temp = prev.front();
                if (temp->left != nullptr)
                    curr.push(temp->left);
                if (temp->right != nullptr)
                    curr.push(temp->right);
                t.push_back(temp->val);
                prev.pop();
            }

            if (c % 2 == 0)
                ans.push_back(t);
            else {
                std::reverse(t.begin(), t.end());
                ans.push_back(t);
            }
            c++;
            prev.swap(curr); // Swap contents of prev and curr queues
        }

        return ans;
    }
};

// Function to create a sample binary tree (for testing)
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution solution;

    TreeNode* root = createSampleTree(); // Create a sample binary tree

    std::vector<std::vector<int>> result = solution.zigzagLevelOrder(root);

    // Print the zigzag level order traversal
    for (const auto& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Clean up memory (delete the tree)
    // ... (write code here to delete the tree and free memory)

    return 0;
}
