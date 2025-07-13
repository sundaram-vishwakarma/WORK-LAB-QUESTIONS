class Solution {
private: 
    int kadanesMax(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0];

        for (int num : nums) {
            sum = max(sum + num, num);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

private:
    int kadanesMin(vector<int>& nums) {
        int sum = 0;
        int minSum = nums[0];

        for (int num : nums) {
            sum = min(sum + num, num);
            minSum = min(minSum, sum);
        }

        return minSum;
    }

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int maxSum = kadanesMax(nums);

        int minSum = kadanesMin(nums);

        int circSum = totalSum - minSum;

        if (maxSum > 0) {
            return max(maxSum, circSum);
        }

        return maxSum;
    }
};
