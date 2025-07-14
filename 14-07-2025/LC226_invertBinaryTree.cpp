class Solution {
private:
    void mirror(TreeNode* root) {
        if (root == nullptr) return;

        // Recursive calls
        mirror(root->left);
        mirror(root->right);

        // Swap left and right child
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        mirror(root);
        return root;
    }
};
