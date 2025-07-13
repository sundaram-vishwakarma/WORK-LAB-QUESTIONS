class Solution {
public:
    // Helper function to check if it's possible to achieve the target size `mid` 
    // with at most `maxOperations` operations
    bool isPossible(const vector<int>& nums, int mid, int maxOperations) {
        int operations = 0;
        for (int num : nums) {
            if (num > mid) {
                int bags = num / mid + (num % mid == 0 ? 0 : 1); // Calculate number of bags needed
                operations += bags - 1;  // Subtract 1 because one bag is already considered
            }
            if (operations > maxOperations) {
                return false;  // If the operations exceed maxOperations, return false
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int right = 0;
        for (int num : nums) {
            right = max(right, num);  // Find the largest number in the array
        }

        int left = 1;
        int result = 0;

        // Binary search for the minimum possible maximum size
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, mid, maxOperations)) {
                result = mid;  // If possible, update the result and try for smaller `mid`
                right = mid - 1;
            } else {
                left = mid + 1;  // If not possible, try for larger `mid`
            }
        }

        return result;  // Return the result
    }
};
