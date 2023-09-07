#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    std::queue<TreeNode*> st;

    void preorder(TreeNode* node) {
        if (node == NULL)
            return;
        preorder(node->left);
        st.push(node);
        preorder(node->right);
    }

    BSTIterator(TreeNode* root) {
        preorder(root);
    }

    int next() {
        if (!st.empty()) {
            TreeNode* temp = st.front();
            st.pop();
            return temp->val;
        }
        return -1;
    }

    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    // Creating a sample binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Creating a BSTIterator object
    BSTIterator iterator(root);

    // Iterating through the BST using the iterator
    while (iterator.hasNext()) {
        std::cout << iterator.next() << " ";
    }
    std::cout << std::endl;

    // Remember to clean up memory (deallocate the tree nodes) properly
    // ...

    return 0;
}
