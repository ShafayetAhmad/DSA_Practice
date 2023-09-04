#include <iostream>
using namespace std;
// Definition for a binary tree node
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
    TreeNode *deleteNode(TreeNode *root, int k)
    {

        if (root == NULL)
            return root;

        if (root->val > k)
        {
            root->left = deleteNode(root->left, k);
            return root;
        }
        else if (root->val < k)
        {
            root->right = deleteNode(root->right, k);
            return root;
        }

        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        else
        {

            TreeNode *succParent = root;

            // Find successor
            TreeNode *succ = root->right;
            while (succ->left != NULL)
            {
                succParent = succ;
                succ = succ->left;
            }

            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            root->val = succ->val;

            delete succ;
            return root;
        }
    }
};

void printInorder(TreeNode *root)
{
    if (root)
    {
        printInorder(root->left);
        std::cout << root->val << " ";
        printInorder(root->right);
    }
}

void deleteTree(TreeNode *root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main()
{
    // Create a sample binary search tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Create an instance of the Solution class
    Solution solution;

    // Call the deleteNode function to delete a node with value 3
    root = solution.deleteNode(root, 3);

    // Print the modified tree (inorder traversal)
    std::cout << "Modified tree (inorder traversal): ";
    printInorder(root);

    // Clean up the memory by deleting the remaining nodes
    deleteTree(root);

    return 0;
}
