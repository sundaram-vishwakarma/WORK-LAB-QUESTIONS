class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelElements;

            while (size > 0) {
                Node* node = q.front();
                q.pop();
                levelElements.push_back(node->val);

                for (Node* child : node->children) {
                    if (child != nullptr) {
                        q.push(child);
                    }
                }

                size--;
            }

            res.push_back(levelElements);
        }

        return res;
    }
