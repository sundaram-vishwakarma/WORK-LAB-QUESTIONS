class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& candidates, int target, int idx, vector<int>& helper) {
        if (target == 0) {
            res.push_back(helper);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;  // after this checking will un useful

            helper.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, helper);  // i + 1 because no reuse
            helper.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // res.clear();

        vector<int> helper;
        backtrack(candidates, target, 0, helper);
        return res;
    }
};

