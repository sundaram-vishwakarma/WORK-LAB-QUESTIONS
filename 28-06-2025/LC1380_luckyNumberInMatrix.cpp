#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();

        // Find the minimum element in each row
        vector<int> rowMins(m);
        for (int i = 0; i < m; i++) {
            int min = matrix[i][0];
            for (int j = 1; j < n; j++) {
                min = min(min, matrix[i][j]);
            }
            rowMins[i] = min;
        }

        // Find the maximum element in each column
        vector<int> colMaxs(n);
        for (int j = 0; j < n; j++) {
            int max = matrix[0][j];
            for (int i = 1; i < m; i++) {
                max = max(max, matrix[i][j]);
            }
            colMaxs[j] = max;
        }

        // Check for lucky numbers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }

        return result;
    }
};

