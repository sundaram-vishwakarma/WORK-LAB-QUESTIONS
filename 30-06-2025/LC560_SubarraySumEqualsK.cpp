class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        
        // HashMap to store the prefix sum and its frequency
        unordered_map<int, int> prefixSumWithPrevCount; 
        prefixSumWithPrevCount[0] = 1; // To handle the case when the sum is exactly k

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Check if there is a previous prefix sum such that sum - previous_sum = k
            if (prefixSumWithPrevCount.find(sum - k) != prefixSumWithPrevCount.end()) {
                count += prefixSumWithPrevCount[sum - k];
            }

            // Update the prefix sum count
            prefixSumWithPrevCount[sum]++;
        }

        return count;
    }
};
