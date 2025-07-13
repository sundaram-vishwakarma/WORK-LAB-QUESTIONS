class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Create an n x n matrix filled with 0
        vector<vector<int>> matrix(n, vector<int>(n));

        int startRow = 0;
        int endRow = n - 1;
        int startCol = 0;
        int endCol = n - 1;

        int val = 1;

        while (startRow <= endRow && startCol <= endCol) {
            // Fill the first Row
            for (int j = startCol; j <= endCol; j++) {
                matrix[startRow][j] = val++;
            }
            startRow++;

            // Fill the end Column
            for (int i = startRow; i <= endRow; i++) {
                matrix[i][endCol] = val++;
            }
            endCol--;

            // Fill the end Row
            if (startRow <= endRow) {
                for (int j = endCol; j >= startCol; j--) {
                    matrix[endRow][j] = val++;
                }
                endRow--;
            }

            // Fill the first Column
            if (startCol <= endCol) {
                for (int i = endRow; i >= startRow; i--) {
                    matrix[i][startCol] = val++;
                }
                startCol++;
            }
        }

        return matrix;
    }
};

