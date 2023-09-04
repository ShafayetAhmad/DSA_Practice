#include <iostream>
#include <vector>
using namespace std;
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
    int searchPosition(vector<int>& inorder, int start, int end, int curr) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == curr)
                return i;
        }
        return -1;
    }

    TreeNode* buildTreeFrom(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        static int idx = 0;
        if (start > end || idx >= preorder.size()) {
            return NULL;
        }
        
        int curr = preorder[idx];
        idx++;
        
        TreeNode* node = new TreeNode(curr);
        if (start == end) {
            return node;
        }
        int pos = searchPosition(inorder, start, end, curr);
        node->left = buildTreeFrom(preorder, inorder, start, pos - 1);
        node->right = buildTreeFrom(preorder, inorder, pos + 1, end);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        TreeNode* root = buildTreeFrom(preorder, inorder, 0, n - 1);
        return root;
    }
};

int main() {
    // Example usage
    Solution solution;

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = solution.buildTree(preorder, inorder);

    // You can now traverse or manipulate the constructed binary tree as needed

    return 0;
}
