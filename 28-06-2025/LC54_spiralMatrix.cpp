class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startRow = 0;
        int endRow = matrix.size() - 1;

        int startCol = 0;
        int endCol = matrix[0].size() - 1;

        // int numberOfElement = matrix.size() * matrix[0].size();
        vector<int> ans;

        while (startRow <= endRow || startCol <= endCol) {
            // for starting row;
            for (int i=startCol; i<=endCol; i++) {
                ans.push_back(matrix[startCol][i]);
            }
            startRow++;

            // for end column
            for (int i=startRow; i<=endRow; i++) {
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;

            // for end Row
            while (startCol <= endCol) {        // due to endCol-- previous LINE: 24
                for (int i=endCol; i>=startCol; i--) {
                    ans.push_back(matix[endRow][i]);
                }
                endRow--;
            }

            // for starting Col
            while (startRow <= endRow) {        // due to startRow++ previous LINE: 18
                for (int i=endRow; i>=startRow; i--) {
                    ans.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }
    }
};
