#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // For reverse
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void traverse(vector<int> &ans, vector<int> &h, TreeNode *root, int height)
    {
        if (root == NULL)
            return;

        if (h[height] == 0)
        {
            ans.push_back(root->val);
            h[height] = 1;
        }
        traverse(ans, h, root->right, height + 1);
        traverse(ans, h, root->left, height + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        vector<int> h(101, 0);
        traverse(ans, h, root, 1);

        return ans;
    }
};

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<int> result = solution.rightSideView(root);

    // Print the right side view
    cout << "Right Side View: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory
    delete root->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
