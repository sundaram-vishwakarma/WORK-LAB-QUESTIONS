class Solution {
private:
    pair<int, int> findCoordinates(int pos, int n) {
        int rowFromTop = (pos - 1) / n;
        int rowFromBottom = (n - 1) - rowFromTop;
        int col = (pos - 1) % n;
        if (rowFromTop % 2 != 0) {
            col = (n - 1) - col;
        }
        return {rowFromBottom, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int curr = q.front();
                q.pop();

                if (curr == n * n) return steps;

                for (int i = 1; i <= 6; ++i) {
                    int next = curr + i;

                    if (next > n * n ) break;
                    
                    if (visited[next]) continue;

                    visited[next] = true;
                    auto [row, col] = findCoordinates(next, n);

                    if (board[row][col] != -1) {
                        q.push(board[row][col]);
                    } else {
                        q.push(next);
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};
