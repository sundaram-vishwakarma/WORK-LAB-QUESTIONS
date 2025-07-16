//// 1. Plain Recursion (TLE for large n)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};




//// 2. Recursion + Memoization (Top-Down DP)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, 0);
        return helper(n, memo);
    }

private:
    int helper(int n, vector<int>& memo) {
        if (n <= 1) return 1;
        if (memo[n] != 0) return memo[n];
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }
};




//// 3. Bottom-Up DP (Tabulation)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};






//// 4. Optimized Bottom-Up DP (Constant Space)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int first = 1, second = 2;
        for (int i = 3; i <= n; ++i) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};
