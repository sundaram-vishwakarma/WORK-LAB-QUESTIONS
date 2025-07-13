class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }

        int curr = 1;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            for (int i = 1; i < k; ++i) {
                q.push(curr);
                curr = q.front();
                q.pop();
            }
        }

        return curr;
    }
};
