class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int maxSum = nums[0];

        for (int num : nums) {
            sum = max(sum + num, num);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
