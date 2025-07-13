class Solution {
public:
    // Helper function to find the insert position using binary search
    int pos(const vector<int>& nums, int i, int j, int target) {
        int mid = (i + j) / 2;
        
        if (target <= nums[i]) {
            return i;
        }
        if (target > nums[j]) {
            return j + 1;
        }
        if (target == nums[mid]) {
            return mid;
        }
        else if (target < nums[mid]) {
            return pos(nums, i, mid - 1, target);
        }
        else {
            return pos(nums, mid + 1, j, target);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        return pos(nums, 0, nums.size() - 1, target);
    }
};
