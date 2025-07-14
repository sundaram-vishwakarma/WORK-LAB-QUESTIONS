class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;  // Base case: if the node is null, the depth is 0.
        }
        
        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The depth of the current node is 1 + the maximum of the left and right subtrees
        return max(leftDepth, rightDepth) + 1;
    }
};
