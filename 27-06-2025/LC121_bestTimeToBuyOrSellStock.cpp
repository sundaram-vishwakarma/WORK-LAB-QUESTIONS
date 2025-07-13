/// Brute Force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        
        for (int i = 0; i < n - 1; i++) {  // O(n^2)
            for (int j = i + 1; j < n; j++) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }
};



/// Optimised
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if (n == 0) return 0;  // Edge case for empty input
        
        vector<int> maxFromLast(n);
        maxFromLast[n-1] = prices[n-1];
        
        for (int i = n - 2; i >= 0; i--) {  // O(n)
            maxFromLast[i] = max(maxFromLast[i + 1], prices[i]);
        }

        vector<int> minFromFirst(n);
        minFromFirst[0] = prices[0];
        
        for (int i = 1; i < n; i++) {  // O(n)
            minFromFirst[i] = min(minFromFirst[i - 1], prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; i++) {  // O(n)
            maxProfit = max(maxProfit, maxFromLast[i] - minFromFirst[i]);
        }

        return maxProfit;
    }
};
