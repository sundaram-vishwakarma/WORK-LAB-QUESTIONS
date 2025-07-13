#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index = 0;
        int prevCount = 0;
        int m = mat.size(); // Number of rows
        int n = mat[0].size(); // Number of columns
        
        // Traverse each row to count the number of 1s
        for (int i = 0; i < m; i++) {
            int currCount = 0;
            // Count the number of 1s in row i
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    currCount++;
                }
            }
            // If the current row has more 1s, update the index and count
            if (currCount > prevCount) {
                index = i;
                prevCount = currCount;
            }
        }
        
        // Return the row index with the maximum number of 1s and the count of 1s
        return {index, prevCount};
    }
};

