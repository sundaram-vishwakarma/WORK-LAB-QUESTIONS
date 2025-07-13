class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int current = 0;

        while (current <= end) {
            if (nums[current] == 0) {     // try to keep it at start
                swap(nums, current, start);
                start++;
                current++;
            }
            else if (nums[current] == 2) {    // try to keep it at end
                swap(nums, current, end);
                end--;
            }
            else {          // remain as it is in the same place
                current++;
            }
        }
    }
};
