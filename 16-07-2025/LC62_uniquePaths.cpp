//// 1. Pure Recursive (Top-Down)
class Solution {
private:
    int way(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) return 1;
        if (i >= m || j >= n) return 0;

        return way(i + 1, j, m, n) + way(i, j + 1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
        return way(0, 0, m, n);
    }
};








///// 2. Recursive + Memoization (Top-Down DP)
class Solution {
private:
    vector<vector<int>> dp;

    int way(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) return 1;
        if (i >= m || j >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = way(i + 1, j, m, n) + way(i, j + 1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return way(0, 0, m, n);
    }
};







////// 3. Tabulation (Bottom-Up DP)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 1));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }

        return grid[m - 1][n - 1];
    }
};
