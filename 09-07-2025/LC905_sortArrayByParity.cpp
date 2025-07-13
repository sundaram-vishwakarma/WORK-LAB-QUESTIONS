class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = -1;  // Pointer for the start of the array
        int j = nums.size() - 1;  // Pointer for the end of the array

        while (i < j) {
            if (nums[j] % 2 == 0) {  // Even number at the end
                i++;
                // Swap the elements
                swap(nums[i], nums[j]);
            } else {
                j--;  // Move the pointer to the left if odd number is found
            }
        }

        return nums;  // Return the sorted array
    }
};
