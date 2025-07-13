///// Brute Force Approach
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> seen;
        int n = grid.size();
        int totalNumbers = n * n;
        
        int repeated = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j];
                if (seen.count(num)) {
                    repeated = num;
                } else {
                    seen.insert(num);
                }
            }
        }
        
        int missing = -1;
        for (int i = 1; i <= totalNumbers; i++) {
            if (seen.count(i) == 0) {
                missing = i;
                break;
            }
        }
        
        return {repeated, missing};
    }
};





//// Optimized Approach
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalNumbers = n * n;
        
        // Sum and sum of squares of numbers from 1 to n^2
        long long expectedSum = (long long)totalNumbers * (totalNumbers + 1) / 2;
        long long expectedSumOfSquares = (long long)totalNumbers * (totalNumbers + 1) * (2 * totalNumbers + 1) / 6;
        
        // Calculate actual sum and sum of squares from the grid
        long long actualSum = 0, actualSumOfSquares = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j];
                actualSum += num;
                actualSumOfSquares += (long long)num * num;
            }
        }
        
        // Use the differences to find the repeated and missing numbers
        long long sumDiff = actualSum - expectedSum; // a - b
        long long sumOfSquaresDiff = actualSumOfSquares - expectedSumOfSquares; // a^2 - b^2
        
        // Solve for a and b using the equations:
        // a - b = sumDiff
        // a^2 - b^2 = sumOfSquaresDiff
        // (a - b) = sumDiff
        // a + b = sumOfSquaresDiff / sumDiff
        
        long long aPlusB = sumOfSquaresDiff / sumDiff;
        long long a = (sumDiff + aPlusB) / 2;
        long long b = a - sumDiff;
        
        return { (int)a, (int)b };
    }
};
