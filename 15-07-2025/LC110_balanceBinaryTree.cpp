class Solution {
private:
    bool valid = true;

    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = height(root->left);

        if (valid) {
            int rightHeight = height(root->right);

            if (abs(leftHeight - rightHeight) > 1) {
                valid = false;
            }

            return max(leftHeight, rightHeight) + 1;
        }

        return -1; // Not used further when valid is false
    }

public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return valid;
    }
};
