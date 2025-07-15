class Solution {
private:
    TreeNode* sortedArrayToBalancedBST(vector<int>& nums, int start, int end) {
        // Base case
        if (start > end) {
            return nullptr;
        }

        // Middle element to keep the tree balanced
        int mid = start + (end - start) / 2;

        // Create root node with mid element
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build left and right subtrees
        root->left = sortedArrayToBalancedBST(nums, start, mid - 1);
        root->right = sortedArrayToBalancedBST(nums, mid + 1, end);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBalancedBST(nums, 0, nums.size() - 1);
    }
};
