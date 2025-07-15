//// using List
class Solution {
private:
    void inorderTraversal(TreeNode* node, vector<int>& list) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left, list);
        list.push_back(node->val);
        inorderTraversal(node->right, list);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderList;
        inorderTraversal(root, inorderList);

        if (k > 0 && k <= inorderList.size()) {
            return inorderList[k - 1];
        } else {
            return -1;
        }
    }
};








////// w/o using List
class Solution {
private:
    int count = 0; // Keeps track of how many nodes we've visited

    int inorderTraversal(TreeNode* node, int k) {
        if (node == nullptr) {
            return -1;
        }

        // Search the left subtree
        int left = inorderTraversal(node->left, k);
        if (left != -1) return left; // If found in the left, return the result

        // Increment the count and check if we've reached the kth smallest
        count++;
        if (count == k) {
            return node->val; // Found the kth smallest element
        }

        // Search the right subtree
        return inorderTraversal(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0; // Reset the count before starting the traversal
        return inorderTraversal(root, k);
    }
};
