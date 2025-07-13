class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Arrays to count the number of servers in each row and column
        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);
        int count = 0;

        // Count the number of servers in each row and column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                    count++;
                }
            }
        }

        // Check if there is only one server in both the row and column, and adjust the count
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (rowCount[i] == 1 && colCount[j] == 1) {
                        count--;
                    }
                }
            }
        }

        return count;
    }
};
