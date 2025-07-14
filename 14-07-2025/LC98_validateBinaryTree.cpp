class Solution {
private:
    bool isValidBST(TreeNode* node, long long lowerBound, long long upperBound) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= lowerBound || node->val >= upperBound) {
            return false;
        }

        return isValidBST(node->left, lowerBound, node->val) && isValidBST(node->right, node->val, upperBound);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};
