class Solution {
public:
    vector<vector<int>> res;
    int n;

    // Backtracking function
    void backtrack(vector<int>& candidates, int target, int idx, vector<int>& helper, int sum) {
        // If the sum matches the target, add the current combination to the result
        if (sum == target) {
            res.push_back(helper);
            return;
        }

        // If the sum exceeds the target or we've considered all elements, stop further exploration
        if (sum > target || idx >= n) {
            return;
        }

        // Iterate over the candidates starting from the current index
        for (int i = idx; i < n; i++) {
            // Include the current candidate in the combination
            helper.push_back(candidates[i]);
            // Recurse with the same index to allow picking the same element again
            backtrack(candidates, target, i, helper, sum + candidates[i]);
            // Backtrack by removing the last element to explore other possibilities
            helper.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();  // Clear the result list before starting
        n = candidates.size();
        
        // Start backtracking from index 0 and initial sum of 0
        backtrack(candidates, target, 0, {}, 0);
        
        return res;
    }
};
