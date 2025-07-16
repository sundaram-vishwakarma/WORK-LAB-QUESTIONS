//// 1. Plain Recursion (TLE for large n)
class Solution {
private:
    int recursion(vector<int>& nums, int i, int n) {
        if (i >= n) return 0;
        int take = nums[i] + recursion(nums, i + 2, n);
        int skip = recursion(nums, i + 1, n);
        return max(take, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return recursion(nums, 0, n);
    }
};





//// 2. Recursion + Memoization (Top-Down DP)
class Solution {
private:
    int recursion(vector<int>& nums, int i, int n, vector<int>& dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int take = nums[i] + recursion(nums, i + 2, n, dp);
        int skip = recursion(nums, i + 1, n, dp);
        return dp[i] = max(take, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return recursion(nums, 0, n, dp);
    }
};





//// 3. Bottom-Up DP (Tabulation)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            int rob = dp[i - 2] + nums[i - 1];
            int notRob = dp[i - 1];
            dp[i] = max(rob, notRob);
        }
        return dp[n];
    }
};






//// 4. Bottom-Up DP (Optimized Space)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int first = 0;
        int mid = nums[0];
        for (int i = 2; i <= n; ++i) {
            int rob = first + nums[i - 1];
            int notRob = mid;
            int last = max(rob, notRob);
            first = mid;
            mid = last;
        }
        return mid;
    }
};
