#include <iostream>
#include <string>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:


    void BTtoStr(TreeNode* root, string &ser){
        if(!root){
            ser += "null "; 
            return;
        }

        ser += to_string(root->val) + ' ';
        BTtoStr(root->left, ser);
        BTtoStr(root->right, ser);

    }
    string serialize(TreeNode* root) {
        string ser = "";
        BTtoStr(root, ser);
        return ser;
    }

    TreeNode* StrToBT(string &data, int &i){
        if(data[i] == 'n'){
            i+=5;  
            return nullptr;
        }

        string tmp = ""; 
        while(data[i] != ' ') 
        tmp += data[i++]; 
        TreeNode* node = new TreeNode(stoi(tmp));
        i++; 
        node->left = StrToBT(data, i);
        node->right = StrToBT(data, i);

        return node;

    }
    TreeNode* deserialize(string data) {
        int i = 0;
        return StrToBT(data, i);
    }
};


int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Creating a codec object
    Codec codec;

    // Serializing the binary tree
    std::string serialized = codec.serialize(root);
    std::cout << "Serialized tree: " << serialized << std::endl;

    // Deserializing the binary tree
    TreeNode* deserializedRoot = codec.deserialize(serialized);

    // Cleaning up the memory
    // (You'll need to implement proper memory deallocation in your TreeNode destructor)
    // ...

    return 0;
}
