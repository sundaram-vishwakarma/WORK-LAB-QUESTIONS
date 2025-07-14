class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: both null
        if (p == nullptr && q == nullptr) return true;

        // One is null or values differ
        if (p == nullptr || q == nullptr || p->val != q->val) return false;

        // Recursively compare left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
