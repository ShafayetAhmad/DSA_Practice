#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void findpath(TreeNode* root, std::vector<TreeNode*>& pt, TreeNode* p) {
        if (root == NULL || p == NULL) {
            return;
        }
        if (p->val == root->val) {
            pt.push_back(root);
            p = NULL;
            return;
        }
        pt.push_back(root);
        findpath(root->left, pt, p);
        findpath(root->right, pt, p);
        if (pt.back() != p) {
            pt.pop_back();
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> pt;
        std::vector<TreeNode*> qt;

        findpath(root, pt, p);
        findpath(root, qt, q);

        TreeNode* lca = NULL;
        int i = 0;

        while (i < pt.size() && i < qt.size() && pt[i] == qt[i]) {
            lca = pt[i];
            i++;
        }

        return lca;
    }
};

int main() {
    Solution solution;

    // Construct a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    if (lca) {
        std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
    } else {
        std::cout << "No Lowest Common Ancestor found." << std::endl;
    }

    // Clean up memory
    // You can implement a function to delete the tree nodes here

    return 0;
}
